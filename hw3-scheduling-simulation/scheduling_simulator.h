#ifndef SCHEDULING_SIMULATOR_H
#define SCHEDULING_SIMULATOR_H
#define STACK_SIZE 8192

#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <sys/time.h>
#include <signal.h>
#include <string.h>
#include "task.h"

enum TASK_STATE {
    TASK_RUNNING,
    TASK_READY,
    TASK_WAITING,
    TASK_TERMINATED
};

typedef struct Task {
    char taskName[8];
    int pid, timeQT, queueTime, suspendTime, state, priority;
    void (* taskFunc)();
    ucontext_t taskContext;
    struct Task *totalQPrev, *totalQNext;
    struct Task *readyQPrev, *readyQNext;
    struct Task *waitingQPrev, *waitingQNext;
} Task;


void pushTotalQ(Task *);
void pushHighReadyQ(Task *);
void pushLowReadyQ(Task *);
void pushWaitingQ(Task *);
Task *deleteTotalQ(int);
Task *deleteHighReadyQ(int);
Task *deleteLowReadyQ(int);
Task *deleteWaitingQ(int);
void taskFinish();
void simulationPause();
void shellMode();
void simulationMode();
void hw_suspend(int msec_10);
void hw_wakeup_pid(int pid);
int hw_wakeup_taskname(char *task_name);
int hw_task_create(char *task_name);
void setTimer();
void timeUP();
void printHighQ();
void printLowQ();
void printwaitingQ();

#endif
