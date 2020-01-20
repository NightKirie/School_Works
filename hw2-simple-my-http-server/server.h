#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/wait.h>
#include <sched.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "status.h"

#define MAX_PAYLOAD 10240

//Check whether path is a file
bool isSupport(char *path)
{
    for(int i = 0; extensions[i].ext != 0; ++i) {
        int len = strlen(extensions[i].ext);
        //if this is a file supported, return true
        if(!strncmp(&path[strlen(path)-len], extensions[i].ext, len)) {
            return true;
        }
    }
    return false;
}

bool isFile(char *path)
{
    struct stat *buff;
    bool returnValue;
    buff = malloc(sizeof(struct stat));
    memset(buff, 0, sizeof(struct stat));
    stat(path, buff);
    if(S_ISREG(buff->st_mode))
        returnValue = true;
    else
        returnValue = false;
    free(buff);
    return returnValue;

}

//Check whether path is a directory
bool isDir(char *path)
{
    struct stat *buff;
    bool returnValue;
    buff = malloc(sizeof(struct stat));
    memset(buff, 0, sizeof(struct stat));
    stat(path, buff);
    if(S_ISDIR(buff->st_mode))
        returnValue = true;
    else
        returnValue = false;
    free(buff);
    return returnValue;
}

//Define the queue's structure
typedef struct queue {
    int capacity;
    int size;
    int front;
    int rear;
    int *elements;
} Queue;

//Create a queue that can store maxElements' thread
Queue* createQueue(int maxElements)
{
    //Create Q with pointer
    Queue *Q;
    Q = (Queue *)malloc(sizeof(Queue));

    //Initialize all the elements
    Q->capacity = maxElements;
    Q->size = 0;
    Q->front = 0;   //front start from first element
    Q->rear = -1;   //rear end to non
    Q->elements = (int *)malloc(sizeof(int) * maxElements); //create a int array to store threads

    return Q;
}

//if a queue is empty, return true, otherwise return false
bool ifQueueEmpty(Queue *Q)
{
    if(Q->size == 0) {
        return true;
    } else {
        return false;
    }
}

//Call this function to pop element from queue
int pop(Queue *Q)
{
    int temp = Q->front;
    if(Q->size != 0) {
        --Q->size;
        ++Q->front;
        //if front go to the queue's tail, then back to the head of the queue, front = 0
        if(Q->front == Q->capacity) {
            Q->front = 0;
        }
        return Q->elements[temp];
    }
    return 0;
}

//Call this function to push an element to queue
void push(Queue *Q, int element)
{
    if(Q->size != Q->capacity) {
        ++Q->size;
        ++Q->rear;

        //if rear reach the end of the queue, rear go back to the first element of the queue
        if(Q->rear == Q->capacity) {
            Q->rear = 0;
        }

        Q->elements[Q->rear] = element;
    }
}

#endif
