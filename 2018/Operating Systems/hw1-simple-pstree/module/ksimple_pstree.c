#include "ksimple_pstree.h"

MODULE_DESCRIPTION("kernel for pid");
MODULE_LICENSE("GPL");

static struct sock *netlink_sock;


static char* dfs(struct task_struct *task, int spaces)
{
    struct task_struct *child;  //for store the child informc
    struct list_head *list = NULL;  //for linked list previous and next task_struct
    char *returnText, *buffer;  //returnText for all the list of processes, buffer for pid
    if(spaces > 0) {    //if recursive more than 0 times, this task is a children
        int i;
        returnText = kmalloc(sizeof(char)*spaces*4+1, GFP_USER);
        memset(returnText, ' ', sizeof(char)*spaces*4);
        returnText[spaces*4] = '\0';
        returnText = krealloc(returnText, strlen(returnText)+strlen(task->comm)+1, GFP_USER);
        strcat(returnText, task->comm);
    } else {    //this is the head of all task
        returnText = kmalloc(strlen(task->comm)+1, GFP_USER);
        strcpy(returnText, task->comm);
    }
    int buffer_len = 3, i;
    for(i = task->pid; i != 0; i/=10)   //for create memory to store "(pid)"
        ++buffer_len;
    buffer = kmalloc(buffer_len, GFP_USER);
    sprintf(buffer, "(%d)\n", task->pid);
    returnText = krealloc(returnText, strlen(returnText)+strlen(buffer)+1, GFP_USER);
    strcat(returnText, buffer);
    ++spaces;
    list_for_each(list, &task->children) {  //Loop over children
        child = list_entry(list, struct task_struct, sibling);  //Get child
        char* temp = dfs(child, spaces);    //get the return of child lists
        returnText = krealloc(returnText, strlen(returnText)+strlen(temp)+1, GFP_USER);
        strcat(returnText, temp);
    }
    return returnText;
}

static char* sibling(struct task_struct *task)
{
    struct task_struct *sib;    //for store the sibling inform
    struct list_head *list = NULL;  //for linked list previous and next task_struct
    char *returnText = NULL;    //returnText for all the list of processes, buffer for pid
    list_for_each(list, &task->sibling) {   //Loop over sibling
        sib = list_entry(list, struct task_struct, sibling);    //Get sibling
        if(sib->pid > 0 && sib->pid <= PID_MAX_LIMIT) {
            if(!returnText) {
                returnText = kmalloc(strlen(sib->comm)+1, GFP_USER);
                strcpy(returnText, sib->comm);
            } else {
                returnText = krealloc(returnText, strlen(returnText)+strlen(sib->comm)+1, GFP_USER);
                strcat(returnText, sib->comm);
            }
            char *buffer;
            int buffer_len = 3, i;
            for(i = task->pid; i != 0; i/=10)
                ++buffer_len;
            buffer = kmalloc(buffer_len, GFP_USER);
            sprintf(buffer, "(%d)\n", sib->pid);
            returnText = krealloc(returnText, strlen(returnText)+strlen(buffer)+1, GFP_USER);
            strcat(returnText, buffer); //DFS from child*/
        }
    }
    if(!returnText)
        return "";
    return returnText;
}

static char* parent(struct task_struct *task)
{
    char *returnText = NULL;
    int spaces = 0;
    printk("I am %s\n", task->comm);
    while(task->pid > 0) {
        printk("%s\n", task->comm);
        if(spaces == 0) {
            returnText = kmalloc(strlen(task->comm)+1, GFP_USER);
            strcpy(returnText, task->comm);
        } else {
            returnText = krealloc(returnText, strlen(returnText)+strlen(task->comm)+1, GFP_USER);
            strcat(returnText, task->comm);
        }
        char *buffer;
        int buffer_len = 4, i;
        for(i = task->pid; i != 0; i/=10)
            ++buffer_len;
        buffer = kmalloc(buffer_len, GFP_USER);
        sprintf(buffer, "(%d) ", task->pid);
        returnText = krealloc(returnText, strlen(returnText)+strlen(buffer)+1, GFP_USER);
        strcat(returnText, buffer);
        task = task->parent;
        ++spaces;
    }
    char *reverseArray[spaces+1];
    char *sepText;
    int i;
    for(i = spaces, sepText = strsep(&returnText, " "); i >= 0 && sepText != NULL; --i, sepText = strsep(&returnText, " ")) {
        if(i != 0) {
            reverseArray[i] = kmalloc((i-1)*4+1, GFP_USER);
            memset(reverseArray[i], ' ', (i-1)*4);
            reverseArray[i][(i-1)*4] = '\0';
            reverseArray[i] = krealloc(reverseArray[i], strlen(reverseArray[i])+strlen(sepText)+1, GFP_USER);
            strcat(reverseArray[i], sepText);
            reverseArray[i] = krealloc(reverseArray[i], strlen(reverseArray[i])+2, GFP_USER);
            strcat(reverseArray[i], "\n");
        }
    }
    kfree(returnText);
    for(i = 1; i < spaces+1; ++i) {
        if(i == 1) {
            returnText = kmalloc(strlen(reverseArray[i])+1, GFP_USER);
            strcpy(returnText, reverseArray[i]);
        } else {
            returnText = krealloc(returnText, strlen(returnText)+strlen(reverseArray[i])+1, GFP_USER);
            strcat(returnText, reverseArray[i]);
        }

    }
    return returnText;
}

static struct task_struct *GetPid(int pid_number)
{
    struct pid *pid;

    pid = find_get_pid(pid_number);
    if(!pid) {
        return NULL;
    }
    return pid_task(pid, PIDTYPE_PID);
}

static char* find_pstree(int pid_number, char option)
{
    struct task_struct *pidData;
    pidData = GetPid(pid_number);

    if(!pidData)
        return "";
    switch(option) {
    case 'c':
        return dfs(pidData, 0);
        break;
    case 's':
        return sibling(pidData);
        break;
    case 'p':
        return parent(pidData);
        break;
    }
    return "";

}

static void udp_reply(int pid,int seq,void *payload)
{
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    int size=strlen(payload)+1;
    int len = NLMSG_SPACE(size);
    void *data;
    int ret;

    skb = alloc_skb(len, GFP_ATOMIC);
    if (!skb)
        return;
    nlh= nlmsg_put(skb, pid, seq, 0, size, 0);
    nlh->nlmsg_flags = 0;
    data=NLMSG_DATA(nlh);
    memcpy(data, payload, size);
    NETLINK_CB(skb).portid = 0; /* from kernel */
    NETLINK_CB(skb).dst_group = 0; /* unicast */
    ret=netlink_unicast(netlink_sock, skb, pid, MSG_DONTWAIT);
    if (ret <0) {
        printk("send failed\n");
        return;
    }
    return;

nlmsg_failure: /* Used by NLMSG_PUT */
    if (skb)
        kfree_skb(skb);
}


/* Receive messages from netlink socket. */
static void udp_receive(struct sk_buff *skb)
{
    u_int pid, seq, sid;
    kuid_t uid;
    void *data;
    struct nlmsghdr *nlh;

    nlh = (struct nlmsghdr *)skb->data;
    pid = NETLINK_CREDS(skb)->pid;
    uid = NETLINK_CREDS(skb)->uid;
    sid = NETLINK_CB(skb).nsid;
    seq = nlh->nlmsg_seq;
    data = NLMSG_DATA(nlh);
    printk("recv skb from user space uid:%d pid:%d seq:%d,sid:%d\n",uid,pid,seq,sid);
    printk("data is :%s\n",(char *)data);
    int input = 0;
    char option = (char)((char *)data)[0];
    kstrtoint(++data, 10, &input);
    char* result = find_pstree(input, option);
    udp_reply(pid,seq,result);
    return;

}

struct netlink_kernel_cfg cfg = {
    .input = udp_receive,
};



static int __init kudp_init(void)
{
    netlink_sock = netlink_kernel_create(&init_net, NETLINK_USERSOCK, &cfg);
    printk(KERN_INFO "netlink driver add successfully\n");
    return 0;
}

static void __exit kudp_exit(void)
{
    sock_release(netlink_sock->sk_socket);
    printk(KERN_INFO "netlink driver remove successfully\n");
}


module_init(kudp_init);
module_exit(kudp_exit);

