#include "server.h"



/*Declare global variables*/
pthread_mutex_t mutex;
pthread_cond_t cond;
Queue* q;
char* root;


/*
 * This function receives receives one number from the client and multiplies
 * it by 10 and sends it back
 */
void doProcessing (int connectFD)
{
    char recvBuff[MAX_PAYLOAD], sendBuff[MAX_PAYLOAD];
    memset(recvBuff, 0, sizeof(recvBuff));
    memset(sendBuff, 0, sizeof(recvBuff));
    /*receive data from the client*/
    int recvlen = recv(connectFD,recvBuff, sizeof(recvBuff),0);
    printf("%s\n",recvBuff);
    //remove \r \n in recv message
    for(int i = 0; i < recvlen; ++i) {
        if(recvBuff[i] == '\r' || recvBuff[i] == '\n')
            recvBuff[i] = 0;
    }

    //find the QUERY_FILE_OR_DIR's start position
    int queryStart = 0;
    for(int i = 0; i < recvlen; ++i) {
        if(recvBuff[i] == ' ') {
            queryStart = i+1;
            break;
        }
    }

    //if QUERY_FILE_OR_DIR doesn't start with a slash, return 400
    if((recvBuff+queryStart)[0] != '/') {
        snprintf(sendBuff, sizeof(sendBuff), "HTTP/1.x %d %s\r\nContent-Type: \r\nServer: httpserver/1.x\r\n\r\n", status_code[BAD_REQUEST], "BAD_REQUEST");
        send(connectFD, sendBuff, strlen(sendBuff),0);
        close(connectFD);
        return;
    }

    //if method is not GET, return 405
    if(strncmp(recvBuff, "GET ", 4)) {
        snprintf(sendBuff, sizeof(sendBuff), "HTTP/1.x %d %s\r\nContent-Type: \r\nServer: httpserver/1.x\r\n\r\n", status_code[METHOD_NOT_ALLOWED], "METHOD_NOT_ALLOWED");
        send(connectFD, sendBuff, strlen(sendBuff),0);
        close(connectFD);
        return;
    }

    //seperate the file/dir with HTTP/1.x
    for(int i = 4; i < strlen(recvBuff); ++i) {
        if(recvBuff[i] == ' ') {
            recvBuff[i] = 0;
            break;
        }
    }

    //concat the root and the file/dir to a path
    char* path = malloc(strlen(root)+strlen(recvBuff)+1-4); //except "GET "
    strcpy(path, root);
    strcat(path, recvBuff+4);

    //if this file/dir not exist
    if(!isFile(path) && !isDir(path)) {
        snprintf(sendBuff, sizeof(sendBuff), "HTTP/1.x %d %s\r\nContent-Type: \r\nServer: httpserver/1.x\r\n\r\n", status_code[NOT_FOUND], "NOT_FOUND");
        send(connectFD, sendBuff, strlen(sendBuff),0);
        close(connectFD);
        return;
    }

    //if this file is not supported, need to check if this is a dir
    if(!isDir(path) && !isSupport(path)) {
        snprintf(sendBuff, sizeof(sendBuff), "HTTP/1.x %d %s\r\nContent-Type: \r\nServer: httpserver/1.x\r\n\r\n", status_code[UNSUPPORT_MEDIA_TYPE], "UNSUPPORT_MEDIA_TYPE");
        send(connectFD, sendBuff, strlen(sendBuff),0);
        close(connectFD);
        return;
    }

    if(isSupport(path)) {
        for(int i = 0; extensions[i].ext != 0; ++i) {
            int len = strlen(extensions[i].ext);
            //if this is a file supported, return true
            if(!strncmp(&path[strlen(path)-len], extensions[i].ext, len)) {
                int fd;
                char fileBuff[MAX_PAYLOAD];
                strcpy(fileBuff, "");
                if((fd = open(path, O_RDONLY)) != -1)  {
                    int end = read(fd, fileBuff, sizeof(fileBuff));
                    fileBuff[end] = '\0';
                    close(fd);
                }
                snprintf(sendBuff, sizeof(sendBuff), "HTTP/1.x %d %s\r\nContent-Type: %s\r\nServer: httpserver/1.x\r\n\r\n%s\r\n", status_code[OK], "OK", extensions[i].mime_type, fileBuff);
            }
        }
    } else if(isDir(path)) {
        snprintf(sendBuff, sizeof(sendBuff), "HTTP/1.x %d %s\r\nContent-Type: %s\r\nServer: httpserver/1.x\r\n\r\n", status_code[OK], "OK", "directory");
        struct dirent *de;
        DIR *dr;
        if((dr = opendir(path)) != NULL)
            while((de = readdir(dr)) != NULL) {
                if(strncmp(de->d_name, "..", 2) && strncmp(de->d_name, ".", 1)) {
                    strcat(sendBuff, de->d_name);
                    strcat(sendBuff, " ");
                }
            }
        strcat(sendBuff, "\r\n\0");
        closedir(dr);
    }
    //snprintf(sendBuff, sizeof(sendBuff), "%s", path);
    send(connectFD, sendBuff, strlen(sendBuff),0);

    close(connectFD);

}

/*
 * This method locks down the connection queue then utilizes the queue.h push function
 * to add a connection to the queue. Then the mutex is unlocked and cond_signal is set
 * to alarm threads in cond_wait that a connection as arrived for reading
 */
void queue_add(int value)
{
    /*Locks the mutex*/
    pthread_mutex_lock(&mutex);

    push(q, value);

    /*Unlocks the mutex*/
    pthread_mutex_unlock(&mutex);

    /* Signal waiting threads */
    pthread_cond_signal(&cond);
}

/*
 * This method locks down the connection queue then utilizes pthread_cond_wait() and waits
 * for a signal to indicate that there is an element in the queue. Then it proceeds to pop the
 * connection off the queue and return it
 */
int queue_get()
{
    /*Locks the mutex*/
    pthread_mutex_lock(&mutex);

    /*Wait for element to become available*/
    while(ifQueueEmpty(q)) {
        //printf("Thread %lu: \tWaiting for Connection\n", pthread_self());
        if(pthread_cond_wait(&cond, &mutex) != 0) {
            perror("Cond Wait Error");
        }
    }

    /*We got an element, pass it back and unblock*/
    int val = pop(q);


    /*Unlocks the mutex*/
    pthread_mutex_unlock(&mutex);

    return val;
}

static void* connectionHandler()
{
    int connectFD = 0;

    /*Wait until tasks is available*/
    while(1) {
        connectFD = queue_get();
        //printf("Handler %lu: \tProcessing\n", pthread_self());
        /*Execute*/
        doProcessing(connectFD);
    }
    return NULL;
}

//./server -r root -p port -n thread_number
int main(int argc, char *argv[])
{

    q = createQueue(256); //create a queue to store the requests

    int listenFD = 0;
    struct sockaddr_in serverAddress;
    int rv;
    int port, threadNumber;

    //Store the root path
    root = malloc(strlen(argv[2])+1);
    strcpy(root, argv[2]);
    if(root[strlen(root)-1] == '/')
        root[strlen(root)-1] = 0;

    //Store the socket port
    port = atoi(argv[4]);

    //Store the total thread number
    threadNumber = atoi(argv[6]);


    /*Initialize the mutex global variable*/
    pthread_mutex_init(&mutex,NULL);

    //Declare a thread pool array that can store threads depends on input
    pthread_t threadPool[threadNumber];

    /*Socket creation and binding*/
    listenFD = socket(AF_INET, SOCK_STREAM, 0);

    if (listenFD <  0) {
        perror("Error in socket creation");
        exit(1);
    }

    memset(&serverAddress, '0', sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(port);

    rv = bind(listenFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    if (rv <  0) {
        perror("Error in binding");
        exit(1);
    }

    //Make a thread pool with threads depends on input
    for(int i = 0; i < threadNumber; i++) {
        pthread_create(&threadPool[i], NULL, connectionHandler, (void *) NULL);
    }

    listen(listenFD, 10);

    /*Accept connection and push them onto the stack*/
    while(1) {
        //printf("\nMain: \t\t\t\tAccepting Connections\n");

        /*The accept call blocks until a connection is found
         * then the connection is pushed onto the queue by queue_add*/
        queue_add(accept(listenFD, (struct sockaddr*)NULL, NULL));

        //printf("Main: \t\t\t\tConnection Completed\n\n");
    }
}



