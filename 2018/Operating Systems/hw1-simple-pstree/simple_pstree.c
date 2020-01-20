#include "simple_pstree.h"

int main(int argc,char *argv[])
{
    struct sockaddr_nl src_addr, dest_addr;
    struct nlmsghdr *nlh = NULL;
    struct iovec iov;
    int sock_fd;
    struct msghdr msg;
    pid_t getpid(void);
    static char *input;

    if(argc == 1) {
        input = malloc(sizeof(char)*3);
        strcpy(input, "c1");
    } else if(argc == 2) {
        switch (argv[1][1]) {
        case 'c':
            if(strlen(argv[1]) == 2) {
                input = malloc(sizeof(char)*3);
                strcpy(input, "c1");
            } else if(strlen(argv[1]) > 2) {
                input = malloc(strlen(argv[1]));
                strcpy(input, ++argv[1]);
            } else {
                return 1;
            }
            break;
        case 's':
            if(strlen(argv[1]) == 2) {
                static char* temp = NULL;
                int temp_len = 1, i;
                for(i = temp_len; i != 0; i/=10)
                    ++temp_len;
                temp = malloc(temp_len);
                sprintf(temp, "%d", getpid());
                input = malloc(sizeof(char)*2);
                strcpy(input, "s");
                input = realloc(input, strlen(input)+strlen(temp)+1);
                strcat(input, temp);
            } else if(strlen(argv[1]) > 2) {
                input = malloc(strlen(argv[1]));
                strcpy(input, ++argv[1]);
            } else {
                return 1;
            }
            break;
        case 'p':
            if(strlen(argv[1]) == 2) {
                static char* temp = NULL;
                int temp_len = 1, i;
                for(i = temp_len; i != 0; i/=10)
                    ++temp_len;
                temp = malloc(temp_len);
                sprintf(temp, "%d", getpid());
                input = malloc(sizeof(char)*2);
                strcpy(input, "p");
                input = realloc(input, strlen(input)+strlen(temp)+1);
                strcat(input, temp);
            } else if(strlen(argv[1]) > 2) {
                input = malloc(strlen(argv[1]));
                strcpy(input, ++argv[1]);
            } else {
                return 1;
            }
            break;
        default:
            input = malloc(sizeof(char)*2);
            strcpy(input, "c");
            input = realloc(input, strlen(input)+strlen(argv[1])+1);
            strcat(input, argv[1]);
        }
    } else {
        return 1;
    }

    sock_fd = socket(PF_NETLINK, SOCK_RAW,NETLINK_USERSOCK);
    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid(); /* self pid */
    src_addr.nl_groups = 0; /* not in mcast groups */
    bind(sock_fd, (struct sockaddr*)&src_addr,sizeof(src_addr));

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; /* For Linux Kernel */
    dest_addr.nl_groups = 0; /* unicast */

    nlh=(struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    /* Fill the netlink message header */
    nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    nlh->nlmsg_pid = getpid(); /* self pid */
    nlh->nlmsg_flags = NLM_F_REQUEST | NLM_F_DUMP;
    nlh->nlmsg_seq = 1;
    /* Fill in the netlink message payload */
    strcpy(NLMSG_DATA(nlh), input);

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;
    msg.msg_name = (void *)&dest_addr;
    msg.msg_namelen = sizeof(dest_addr);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    sendmsg(sock_fd, &msg, 0);


    /* Read message from kernel */
    recvmsg(sock_fd, &msg, 0);

    if(strcmp(NLMSG_DATA(msg.msg_iov->iov_base), "") != 0)
        printf("%s",NLMSG_DATA(msg.msg_iov->iov_base));
    close(sock_fd);
    return 0;
}
