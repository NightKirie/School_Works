#include "client.h"


char *localhost = NULL, *port = NULL, outputDir[] = "./output";
/*
 * The function get_sockaddr converts the server's address and port into a form usable to create a
 * scoket
*/
struct addrinfo* get_sockaddr(const char* hostname, const char *port)
{

    struct addrinfo hints;
    struct addrinfo* results;
    int rv;

    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_INET;          //Return socket address for the server's IPv4 addresses
    hints.ai_socktype = SOCK_STREAM;    //Return TCP socket addresses

    /* Use getaddrinfo will get address information for the host specified by hostnae */

    rv = getaddrinfo(hostname, port, &hints, &results);
    if (rv != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    return results;
}

/*
 * The function open_connection establishes a connection to the server
*/
int open_connection(struct addrinfo* addr_list)
{

    struct addrinfo* p;
    int sockfd;
    //Iterate through each addr info in the list; Stop when we successully connect to one

    for (p = addr_list; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        // Try the next address since the socket operation failed
        if (sockfd == -1) continue;

        //Stop iterating of we are able to connect to the server

        if (connect(sockfd,p->ai_addr, p->ai_addrlen) != -1) break;
    }

    freeaddrinfo(addr_list);

    if (p == NULL)
        err(EXIT_FAILURE, "%s", "Unable to connect");
    else
        return sockfd;

}

void makeRequest(char *inputRequest, char *localhost, char *port, char *sendBuff)
{
    snprintf(sendBuff, MAX_PAYLOAD, "GET %s HTTP/1.x\r\nHOST: %s:%s \r\n\r\n", inputRequest, localhost, port);
    return;
}

void* child(void* recvData)
{
    char sendBuff[MAX_PAYLOAD];
    char recvBuff[MAX_PAYLOAD];
    memset(sendBuff, 0,sizeof(sendBuff));
    memset(recvBuff, 0,sizeof(recvBuff));
    struct addrinfo* results = get_sockaddr(localhost, port);
    int sockfd = open_connection(results);
    makeRequest((char *)recvData, localhost, port, sendBuff);
    //printf("S: %s\n", sendBuff);
    send(sockfd, sendBuff, strlen(sendBuff), 0);
    recv(sockfd, recvBuff, sizeof(recvBuff), 0);
    pthread_exit(recvBuff);
}


void loopFind(char* recvBuff, char *parentDir)
{
    printf("%s\n", recvBuff);
    if(!strncmp(recvBuff, "HTTP/1.x 200 OK", 14)) {
        //if it's a directory, need to create thread to DFS through elements
        if(!strncmp(recvBuff+31, "directory", 9)) {
            struct stat st = {0};
            char *outputThis = (char *)malloc(strlen(outputDir)+strlen(parentDir)+1);
            strcpy(outputThis, outputDir);
            strcat(outputThis, parentDir);
            //if dir doesn't exist, loop through dir to make each dir
            for(int i = 0; i < strlen(outputThis); ++i) {
                if(outputThis[i] == '/') {
                    outputThis[i] = 0;
                    if (stat(outputThis, &st) == -1)
                        mkdir(outputThis, 0700);
                    outputThis[i] = '/';
                }
            }
            if (stat(outputThis, &st) == -1) {
                mkdir(outputThis, 0700);
            }
            free(outputThis);

            //if there's still things in directory
            if(strlen(recvBuff) > 70) {
                char *recvData[MAX_PAYLOAD];// = malloc(strlen(recvBuff+68)+1);
                char *wholeList = (char *)malloc(strlen(recvBuff+68)+1);
                int recvDataStart = 0;
                strcpy(wholeList, recvBuff+68);
                strtok(wholeList, " ");

                //loop through all the elements
                while(wholeList != NULL) {
                    if(strcmp(wholeList, "\r\n")) {
                        recvData[recvDataStart] = (char *)malloc(strlen(wholeList)+1);
                        strcpy(recvData[recvDataStart], wholeList);
                        ++recvDataStart;
                    }
                    wholeList = strtok(NULL, " ");
                }
                for(int i = 0; i < recvDataStart; ++i) {
                    pthread_t t;
                    void *recvMsg, *temp;
                    temp = malloc(strlen(recvData[i])+strlen(parentDir)+2);
                    strcpy(temp, parentDir);
                    strcat(temp, "/");
                    strcat(temp, recvData[i]);
                    pthread_create(&t, NULL, child, temp);
                    pthread_join(t, &recvMsg);
                    loopFind(recvMsg, temp);
                }
                free(wholeList);
                return;
            }
            //else it is a file
        } else {
            char *outputThis = (char *)malloc(strlen(outputDir)+strlen(parentDir)+1);
            strcpy(outputThis, outputDir);
            strcat(outputThis, parentDir);
            //make sure the dir is exist
            struct stat st = {0};
            for(int i = 0; i < strlen(outputThis); ++i) {
                if(outputThis[i] == '/') {
                    outputThis[i] = 0;
                    if (stat(outputThis, &st) == -1)
                        mkdir(outputThis, 0700);
                    outputThis[i] = '/';
                }
            }
            FILE *fp = fopen(outputThis, "w");
            recvBuff = strstr(recvBuff, "\r\n\r\n");
            if(fp)
                fprintf(fp, "%s", recvBuff+4);
            fclose(fp);
            free(outputThis);
            return;
        }
    }
    return;


}

//./client -t FILE_OR_DIR -h LOCALHOST -p port
int main(int argc, char *argv[])
{
    char sendBuff[MAX_PAYLOAD];
    char recvBuff[MAX_PAYLOAD];
    //struct hostent *server;
    char *inputRequest = NULL;

    //Store the input request
    inputRequest = malloc(strlen(argv[2]) + 1);
    strcpy(inputRequest, argv[2]);

    //Store the ip of local host
    localhost = malloc(strlen(argv[4]) + 1);
    strcpy(localhost, argv[4]);

    //Store the socket port
    port = malloc(strlen(argv[6]) + 1);
    strcpy(port, argv[6]);

    struct addrinfo* results = get_sockaddr(localhost, port);
    int sockfd = open_connection(results);

    memset(sendBuff, 0,sizeof(sendBuff));
    memset(recvBuff, 0,sizeof(recvBuff));

    makeRequest(inputRequest, localhost, port, sendBuff);
    send(sockfd, sendBuff, strlen(sendBuff), 0);
    recv(sockfd, recvBuff, sizeof(recvBuff), 0);

    //if receive ok from server
    loopFind(recvBuff, inputRequest);

    free(inputRequest);
    free(localhost);
    free(port);


    return 0;
}
