#include "scheduling_simulator.h"

ucontext_t shell, simulation, finish;
struct itimerval timerRR;
Task *totalQH = NULL, *totalQT = NULL;
Task *highQH = NULL, *highQT = NULL;
Task *lowQH = NULL, *lowQT = NULL;
Task *waitingQH = NULL, *waitingQT = NULL;
Task *runningTask = NULL;

int main()
{
    //signal(SIGALRM, timeUP);
    //signal(SIGTSTP, simulationPause);

    struct sigaction timeup;
    timeup.sa_handler = timeUP;
    timeup.sa_flags = 0;
    sigemptyset(&timeup.sa_mask);
    sigaddset(&timeup.sa_mask, SIGALRM);
    if(sigaction(SIGALRM, &timeup, NULL) < 0)
        return 0;

    struct sigaction pause;
    pause.sa_handler = simulationPause;
    pause.sa_flags = 0;
    sigemptyset(&pause.sa_mask);
    sigaddset(&pause.sa_mask, SIGTSTP);
    if(sigaction(SIGTSTP, &pause, NULL) < 0)
        return 0;

    getcontext(&shell);
    shell.uc_link = 0;
    shell.uc_stack.ss_sp = malloc(STACK_SIZE);
    shell.uc_stack.ss_size = STACK_SIZE;
    shell.uc_stack.ss_flags = 0;
    makecontext(&shell, shellMode, 0);

    getcontext(&simulation);
    simulation.uc_link = 0;
    simulation.uc_stack.ss_sp = malloc(STACK_SIZE);
    simulation.uc_stack.ss_size = STACK_SIZE;
    simulation.uc_stack.ss_flags = 0;
    makecontext(&simulation, simulationMode, 0);

    getcontext(&finish);
    finish.uc_link = 0;
    finish.uc_stack.ss_sp = malloc(STACK_SIZE);
    finish.uc_stack.ss_size = STACK_SIZE;
    finish.uc_stack.ss_flags = 0;
    makecontext(&finish, taskFinish, 0);

    setcontext(&shell);
    return 0;
}

void shellMode()
{
    size_t inputSize = 64;
    char *input = malloc(inputSize);
    int pid, timeQT, priority;

    while(1) {
        // get user command
        printf("$ ");
        getline(&input, &inputSize, stdin);
        input[strlen(input)-1] = 0;		// remove \n

        // get elements in command, to simulate argc & argv
        int argc = 1;	// initialize to 1 for "add"
        char *findSpace = strchr(input, ' ');
        while(findSpace != NULL && strcmp(findSpace, " ")) {
            ++argc;
            findSpace = strchr(findSpace+1, ' ');
        }
        char *argv[argc], *eachElement = strtok(input, " ");
        for(int i = 0; i < argc && eachElement != NULL; ++i) {
            argv[i] = malloc(strlen(eachElement) + 1);
            strcpy(argv[i], eachElement);
            eachElement = strtok(NULL, " ");
        }

        // for command add
        if(!strcmp(argv[0], "add")) {
            // check if command is legalmultiple definition of `pushTotalQ'
            switch(argc) {
            case 2:
                pid = hw_task_create(argv[1]);
                timeQT = 10;
                priority = 0;
                break;
            case 4:
                // check if argv[2] is -t, -p, or others
                if(!strcmp(argv[2], "-t")) {
                    if(!strcmp(argv[3], "S"))
                        timeQT = 10;
                    else if(!strcmp(argv[3], "L"))
                        timeQT = 20;
                    else {
                        printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                        continue;
                    }
                    priority = 0;
                } else if(!strcmp(argv[2], "-p")) {
                    if(!strcmp(argv[3], "L"))
                        priority = 0;
                    else if(!strcmp(argv[3], "H"))
                        priority = 1;
                    else {
                        printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                        continue;
                    }
                    timeQT = 10;
                } else {
                    printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                    continue;
                }
                pid = hw_task_create(argv[1]);
                break;
            case 6:
                // check if argv[2] is -t, -p, or others
                if(!strcmp(argv[2], "-t")) {
                    if(!strcmp(argv[3], "S"))
                        timeQT = 10;
                    else if(!strcmp(argv[3], "L"))
                        timeQT = 20;
                    else {
                        printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                        continue;
                    }
                } else if(!strcmp(argv[2], "-p")) {
                    if(!strcmp(argv[3], "L"))
                        priority = 0;
                    else if(!strcmp(argv[3], "H"))
                        priority = 1;
                    else {
                        printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                        continue;
                    }
                } else {
                    printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                    continue;
                }

                // check if argv[4] is -t, -p, same with argv[2], or others
                if(!strcmp(argv[4], argv[2])) {
                    printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                    continue;
                } else if(!strcmp(argv[4], "-t")) {
                    if(!strcmp(argv[5], "S"))
                        timeQT = 10;
                    else if(!strcmp(argv[5], "L"))
                        timeQT = 20;
                    else {
                        printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                        continue;
                    }
                } else if(!strcmp(argv[4], "-p")) {
                    if(!strcmp(argv[5], "L"))
                        priority = 0;
                    else if(!strcmp(argv[5], "H"))
                        priority = 1;
                    else {
                        printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                        continue;
                    }
                } else {
                    printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                    continue;
                }
                pid = hw_task_create(argv[1]);
                break;
            default:
                printf("Usage: add <TASK_NAME> (optional -t <TIME_QUANTUM(L/S)> -p <PRIORITY(H/L)>)\n");
                continue;
            }

            //check if task exist
            if(pid == -1) {
                printf("Input task doesn't exist\n");
                continue;
            } else {
                totalQT->timeQT = timeQT;
                totalQT->priority = priority;
                if(priority == 1) { //if priority is high, change the ready queue to high
                    Task *ptr = deleteLowReadyQ(-2);
                    pushHighReadyQ(ptr);
                }
            }
        }
        // for command remove
        else if(!strcmp(argv[0], "remove")) {
            if(argc != 2) {
                printf("Usage: remove <pid>\n");
                continue;
            }
            pid = atoi(argv[1]);
            Task *ptr = deleteTotalQ(pid);
            if(ptr == NULL) {
                printf("Task queue is empty\n");
                continue;
            }
            if(ptr->state == TASK_WAITING)
                deleteWaitingQ(pid);
            else if(ptr->priority == 1)
                deleteHighReadyQ(pid);
            else
                deleteLowReadyQ(pid);
            free(ptr->taskContext.uc_stack.ss_sp);
            free(ptr);
        }
        // for command ps
        else if(!strcmp(argv[0], "ps")) {
            if(argc > 2) {
                printf("Usage: ps\n");
                continue;
            }
            if(argc == 1) {
                if(totalQH == NULL)
                    printf("Task queue is empty\n");
                else {
                    Task *ptr = totalQH;
                    while(ptr != NULL) {
                        printf("%3d  %s  ", ptr->pid, ptr->taskName);
                        switch(ptr->state) {
                        case TASK_RUNNING:
                            printf("TASK_RUNNING     %5d  ", ptr->queueTime);
                            break;
                        case TASK_READY:
                            printf("TASK_READY       %5d  ", ptr->queueTime);
                            break;
                        case TASK_WAITING:
                            printf("TASK_WAITING     %5d  ", ptr->queueTime);
                            break;
                        case TASK_TERMINATED:
                            printf("TASK_TERMINATED  %5d  ", ptr->queueTime);
                            break;
                        }
                        if(ptr->priority == 0)
                            printf("L  ");
                        else
                            printf("H  ");
                        if(ptr->timeQT == 10)
                            printf("S\n");
                        else
                            printf("L\n");
                        ptr = ptr->totalQNext;
                    }
                }
            } else if(argc == 2) {
                if(!strcmp(argv[1], "-h"))
                    printHighQ();
                else if(!strcmp(argv[1], "-l"))
                    printLowQ();
                else if(!strcmp(argv[1], "-w"))
                    printwaitingQ();
                else {
                    printf("Usage: ps\n");
                    continue;
                }
            }

        }
        //for clean the task's in queue
        else if (!strcmp(argv[0], "clear")) {
            Task *ptr = totalQH;
            while(ptr != NULL) {
                deleteTotalQ(ptr->pid);
                if(ptr->state == TASK_READY || ptr->state == TASK_RUNNING) {
                    if(ptr->priority == 1)
                        deleteHighReadyQ(ptr->pid);
                    else
                        deleteLowReadyQ(ptr->pid);
                } else if(ptr->state == TASK_WAITING)
                    deleteWaitingQ(ptr->pid);
                free(ptr->taskContext.uc_stack.ss_sp);
                free(ptr);
                ptr = totalQH;
            }
            continue;
        }
        // for command start
        else if(!strcmp(argv[0], "start")) {
            if(argc != 1) {
                printf("Usage: start\n");
                continue;
            }
            printf("simulating...\n");
            setcontext(&simulation);
        } else
            printf("Unsupport command\n");
    }
}

void simulationMode()
{
    if(totalQH == NULL) {
        printf("There's no task in queue\n");
        setcontext(&shell);
        return;
    }

    //run high priority first
    if(highQH != NULL) {
        runningTask = highQH;
        runningTask->state = TASK_RUNNING;
        setTimer(runningTask->timeQT*1000);
        setcontext(&(runningTask->taskContext));
        return;
    }

    //then run low priority
    if(lowQH != NULL) {
        runningTask = lowQH;
        runningTask->state = TASK_RUNNING;
        setTimer(runningTask->timeQT*1000);
        setcontext(&(runningTask->taskContext));
        return;
    }

    //no task to run, check waiting Q
    if(waitingQH != NULL) {
        Task *ptr = waitingQH;
        while(ptr != NULL) {
            runningTask = ptr;
            setTimer(runningTask->timeQT*1000);
            while(1);
        }
    }
    printf("Tasks all done\n");
    setcontext(&shell);
}

void taskFinish()
{
    setTimer(0);
    printf("###%s pid=%d finish###\n", runningTask->taskName, runningTask->pid);
    runningTask->state = TASK_TERMINATED;
    if(runningTask->priority == 1)
        deleteHighReadyQ(runningTask->pid);
    else
        deleteLowReadyQ(runningTask->pid);
    setcontext(&simulation);
}

void simulationPause()
{
    setTimer(0);
    printf("\nPause\n");
    if(runningTask != NULL && runningTask->state == TASK_RUNNING) {
        swapcontext(&(runningTask->taskContext), &shell);
        return;
    } else {
        setcontext(&shell);
        return;
    }
}

void hw_suspend(int msec_10)
{
    setTimer(0);
    runningTask->state = TASK_WAITING;
    runningTask->suspendTime = msec_10 * 10;
    if(runningTask->priority == 1)
        deleteHighReadyQ(runningTask->pid);
    else
        deleteLowReadyQ(runningTask->pid);
    pushWaitingQ(runningTask);
    printf("###%s pid=%d suspend###\n", runningTask->taskName, runningTask->pid);
    swapcontext(&(runningTask->taskContext), &simulation);
    return;
}

void hw_wakeup_pid(int pid)
{
    if(waitingQH == NULL) {
        printf("Waiting queue is empty\n");
        return;
    } else {
        Task *wakenTask = deleteWaitingQ(pid);
        printf("###%s pid=%d wake up###\n", wakenTask->taskName, wakenTask->pid);
        wakenTask->state = TASK_READY;
        wakenTask->suspendTime = 0;
        if(wakenTask->priority == 1)
            pushHighReadyQ(wakenTask);
        else
            pushLowReadyQ(wakenTask);
    }
    return;
}

int hw_wakeup_taskname(char *task_name)
{
    if(waitingQH == NULL) {
        printf("Task not found\n");
        return -1;
    } else {
        Task *ptr = waitingQH;
        int wakenTaskNum = 0;
        while(ptr != NULL) {
            if(!strcmp(ptr->taskName, task_name)) {
                ptr->state = TASK_READY;
                ptr->suspendTime = 0;
                ++wakenTaskNum;
                printf("###%s pid=%d wake up###\n", ptr->taskName, ptr->pid);
                Task *wakenTask = ptr; //use to store the task to remove from waiting queue
                ptr = ptr->waitingQNext;    //select next task to decrease suspend time
                deleteWaitingQ(wakenTask->pid);
                if(wakenTask->priority == 1)
                    pushHighReadyQ(wakenTask);
                else
                    pushLowReadyQ(wakenTask);
            } else  //if this task isn't match the task name, select next one
                ptr = ptr->waitingQNext;
        }
        return wakenTaskNum;
    }
    return 0;
}

int hw_task_create(char *task_name)
{
    static int taskPid = 0;
    void (* taskFunc)() = NULL;

    //check if input task exist
    if(!strcmp(task_name, "task1")) {
        taskFunc = task1;
    } else if(!strcmp(task_name, "task2")) {
        taskFunc = task2;
    } else if(!strcmp(task_name, "task3")) {
        taskFunc = task3;
    } else if(!strcmp(task_name, "task4")) {
        taskFunc = task4;
    } else if(!strcmp(task_name, "task5")) {
        taskFunc = task5;
    } else if(!strcmp(task_name, "task6")) {
        taskFunc = task6;
    } else
        return -1;
    //create a new task, and initializes it's elements
    Task *newTask = (Task *)malloc(sizeof(Task));
    ++taskPid;
    strcpy(newTask->taskName, task_name);
    newTask->pid = taskPid;
    newTask->timeQT = 10;	//default is 10
    newTask->priority = 0;	//default is low(0)
    newTask->queueTime = 0;
    newTask->suspendTime = 0;
    newTask->state = TASK_READY;
    newTask->taskFunc = taskFunc;
    newTask->totalQPrev = NULL;
    newTask->totalQNext = NULL;
    newTask->readyQPrev = NULL;
    newTask->readyQNext = NULL;
    newTask->waitingQPrev = NULL;
    newTask->waitingQNext = NULL;

    getcontext(&(newTask->taskContext));
    newTask->taskContext.uc_link = &finish;
    newTask->taskContext.uc_stack.ss_sp = malloc(STACK_SIZE);
    newTask->taskContext.uc_stack.ss_size = STACK_SIZE;
    newTask->taskContext.uc_stack.ss_flags = 0;
    makecontext(&(newTask->taskContext), newTask->taskFunc, 0);
    printf("###%s pid=%d create###\n", newTask->taskName, newTask->pid);
    pushTotalQ(newTask);
    pushLowReadyQ(newTask);  //default push newtask to low, later change if need
    return taskPid; // the pid of created task name
}

void setTimer(int usec)
{
    timerRR.it_value.tv_sec = usec / 1000000;
    timerRR.it_value.tv_usec = usec % 1000000;
    setitimer(ITIMER_REAL, &timerRR, NULL);
    return;
}

void timeUP()
{
    setTimer(0);
    //increase the queue time of high/low ready queue
    Task *ptr = highQH;
    while(ptr != NULL) {
        if(ptr->state == TASK_READY) {
            ptr->queueTime += runningTask->timeQT;
        }
        ptr = ptr->readyQNext;
    }
    ptr = lowQH;
    while(ptr != NULL) {
        if(ptr->state == TASK_READY) {
            ptr->queueTime += runningTask->timeQT;
        }
        ptr = ptr->readyQNext;
    }
    //decrease the waiting time of waiting task
    ptr = waitingQH;
    while(ptr != NULL) {
        ptr->suspendTime = ptr->suspendTime - runningTask->timeQT;
        //suspend timeup, wake up the task
        if(ptr->suspendTime <= 0) {
            printf("%s pid=%d wake up\n", ptr->taskName, ptr->pid);
            ptr->state = TASK_READY;
            ptr->suspendTime = 0;
            Task *wakenTask = ptr; //use to store the task to remove from waiting queue
            ptr = ptr->waitingQNext;    //select next task to decrease suspend time
            deleteWaitingQ(wakenTask->pid);
            if(wakenTask->priority == 1)
                pushHighReadyQ(wakenTask);
            else
                pushLowReadyQ(wakenTask);
        }
        //waiting not finish, select next one
        else
            ptr = ptr->waitingQNext;
    }

    //select next task to run
    if(runningTask->state == TASK_RUNNING) {
        runningTask->state = TASK_READY;
        //Task *timeoutTask = runningTask; //to store the timeout task, later will change next task to run
        if(runningTask->priority == 1) {
            deleteHighReadyQ(runningTask->pid);
            pushHighReadyQ(runningTask);

        } else {
            deleteLowReadyQ(runningTask->pid);
            pushLowReadyQ(runningTask);
        }
        swapcontext(&(runningTask->taskContext), &simulation);
        return;
    } else if(runningTask->state == TASK_WAITING || runningTask->state == TASK_READY ) {
        setcontext(&simulation);
        return;
    }
    return;
}

void pushTotalQ(Task *task)
{
    if(totalQH == NULL) {
        totalQH = task;
        totalQT = task;
    } else {
        task->totalQPrev = totalQT;
        totalQT->totalQNext = task;
        totalQT = task;
    }
}

void pushHighReadyQ(Task *task)
{
    if(highQH == NULL) {
        highQH = task;
        highQT = task;
    } else {
        task->readyQPrev = highQT;
        highQT->readyQNext = task;
        highQT = task;
    }
}


void pushLowReadyQ(Task *task)
{
    if(lowQH == NULL) {
        lowQH = task;
        lowQT = task;
    } else {
        task->readyQPrev = lowQT;
        lowQT->readyQNext = task;
        lowQT = task;
    }
}

void pushWaitingQ(Task *task)
{
    if(waitingQH == NULL) {
        waitingQH = task;
        waitingQT = task;
    } else {
        task->waitingQPrev = waitingQT;
        waitingQT->waitingQNext = task;
        waitingQT = task;
    }
}

Task *deleteTotalQ(int pid)
{
    if(totalQT == NULL)
        return NULL;
    else {
        if(totalQH->pid == pid || pid == -1) { //-1 for popfront
            Task *ptr = totalQH;
            if(totalQH == totalQT) {
                totalQH = NULL;
                totalQT = NULL;
                return ptr;
            } else {
                totalQH = totalQH->totalQNext;
                totalQH->totalQPrev = NULL;
                ptr->totalQNext = NULL;
                return ptr;
            }
        } else if(totalQT->pid == pid || pid == -2) {  //-2 for popback
            Task *ptr = totalQT;
            if(totalQH == totalQT) {
                totalQH = NULL;
                totalQT = NULL;
                return ptr;
            } else {
                totalQT = ptr->totalQPrev;
                totalQT->totalQNext = NULL;
                ptr->totalQPrev = NULL;
                return ptr;
            }
        } else {
            Task *ptr = totalQH->totalQNext;
            while(ptr->totalQNext != NULL) {
                if(ptr->pid == pid) {
                    ptr->totalQPrev->totalQNext = ptr->totalQNext;
                    ptr->totalQNext->totalQPrev = ptr->totalQPrev;
                    ptr->totalQNext = NULL;
                    ptr->totalQPrev = NULL;
                    return ptr;
                }
            }
            return NULL;
        }
    }
}

Task *deleteHighReadyQ(int pid)
{

    if(highQH == NULL)
        return NULL;
    else {
        if(highQH->pid == pid || pid == -1) { //-1 for popfront
            Task *ptr = highQH;
            if(highQH == highQT) {
                highQH = NULL;
                highQT = NULL;
                return ptr;
            } else {
                highQH = highQH->readyQNext;
                highQH->readyQPrev = NULL;
                ptr->readyQNext = NULL;
                return ptr;
            }
        } else if(highQT->pid == pid || pid == -2) {  //-2 for popback
            Task *ptr = highQT;
            if(highQH == highQT) {
                highQH = NULL;
                highQT = NULL;
                return ptr;
            } else {
                highQT = ptr->readyQPrev;
                highQT->readyQNext = NULL;
                ptr->readyQPrev = NULL;
                return ptr;
            }
        } else {
            Task *ptr = highQH->readyQNext;
            while(ptr->readyQNext != NULL) {
                if(ptr->pid == pid) {
                    ptr->readyQPrev->readyQNext = ptr->readyQNext;
                    ptr->readyQNext->readyQPrev = ptr->readyQPrev;
                    ptr->readyQNext = NULL;
                    ptr->readyQPrev = NULL;
                    return ptr;
                }
            }
            return NULL;
        }
    }
}

Task *deleteLowReadyQ(int pid)
{
    if(lowQH == NULL)
        return NULL;
    else {
        if(lowQH->pid == pid || pid == -1) { //-1 for popfront
            Task *ptr = lowQH;
            if(lowQH == lowQT) {
                lowQH = NULL;
                lowQT = NULL;
                return ptr;
            } else {
                lowQH = lowQH->readyQNext;
                lowQH->readyQPrev = NULL;
                ptr->readyQNext = NULL;
                return ptr;
            }
        } else if(lowQT->pid == pid || pid == -2) {  //-2 for popback
            Task *ptr = lowQT;
            if(lowQH == lowQT) {
                lowQH = NULL;
                lowQT = NULL;
                return ptr;
            } else {
                lowQT = ptr->readyQPrev;
                lowQT->readyQNext = NULL;
                ptr->readyQPrev = NULL;
                return ptr;
            }
        } else {
            Task *ptr = lowQH->readyQNext;
            while(ptr->readyQNext != NULL) {
                if(ptr->pid == pid) {
                    ptr->readyQPrev->readyQNext = ptr->readyQNext;
                    ptr->readyQNext->readyQPrev = ptr->readyQPrev;
                    ptr->readyQNext = NULL;
                    ptr->readyQPrev = NULL;
                    return ptr;
                }
            }
            return NULL;
        }
    }
}

Task *deleteWaitingQ(int pid)
{
    if(waitingQH == NULL)
        return NULL;
    else {
        if(waitingQH->pid == pid || pid == -1) { //-1 for popfront
            Task *ptr = waitingQH;
            if(waitingQH == waitingQT) {
                waitingQH = NULL;
                waitingQT = NULL;
                return ptr;
            } else {
                waitingQH = waitingQH->waitingQNext;
                waitingQH->waitingQPrev = NULL;
                ptr->waitingQNext = NULL;
                return ptr;
            }
        } else if(waitingQT->pid == pid || pid == -2) {  //-2 for popback
            Task *ptr = waitingQT;
            if(waitingQH == waitingQT) {
                waitingQH = NULL;
                waitingQT = NULL;
                return ptr;
            } else {
                waitingQT = ptr->waitingQPrev;
                waitingQT->waitingQNext = NULL;
                ptr->waitingQPrev = NULL;
                return ptr;
            }
        } else {
            Task *ptr = waitingQH->waitingQNext;
            while(ptr->waitingQNext != NULL) {
                if(ptr->pid == pid) {
                    ptr->waitingQPrev->waitingQNext = ptr->waitingQNext;
                    ptr->waitingQNext->waitingQPrev = ptr->waitingQPrev;
                    ptr->waitingQNext = NULL;
                    ptr->waitingQPrev = NULL;
                    return ptr;
                }
            }
            return NULL;
        }
    }
}

void printHighQ()
{
    if(highQH == NULL)
        printf("High priority task queue is empty\n");
    else {
        Task* ptr = highQH;
        while(ptr != NULL) {
            printf("%3d  %s  ", ptr->pid, ptr->taskName);
            switch(ptr->state) {
            case TASK_RUNNING:
                printf("TASK_RUNNING     %5d  ", ptr->queueTime);
                break;
            case TASK_READY:
                printf("TASK_READY       %5d  ", ptr->queueTime);
                break;
            case TASK_WAITING:
                printf("TASK_WAITING     %5d  ", ptr->queueTime);
                break;
            case TASK_TERMINATED:
                printf("TASK_TERMINATED  %5d  ", ptr->queueTime);
                break;
            }
            if(ptr->timeQT == 10)
                printf("S\n");
            else
                printf("L\n");
            ptr = ptr->readyQNext;
        }
    }
}
void printLowQ()
{
    if(lowQH == NULL)
        printf("Low priority task queue is empty\n");
    else {
        Task* ptr = lowQH;
        while(ptr != NULL) {
            printf("%3d  %s  ", ptr->pid, ptr->taskName);
            switch(ptr->state) {
            case TASK_RUNNING:
                printf("TASK_RUNNING     %5d  ", ptr->queueTime);
                break;
            case TASK_READY:
                printf("TASK_READY       %5d  ", ptr->queueTime);
                break;
            case TASK_WAITING:
                printf("TASK_WAITING     %5d  ", ptr->queueTime);
                break;
            case TASK_TERMINATED:
                printf("TASK_TERMINATED  %5d  ", ptr->queueTime);
                break;
            }
            if(ptr->timeQT == 10)
                printf("S\n");
            else
                printf("L\n");
            ptr = ptr->readyQNext;
        }
    }
}
void printwaitingQ()
{
    if(waitingQH == NULL)
        printf("Waiting task queue is empty\n");
    else {
        Task *ptr = waitingQH;
        while(ptr != NULL) {
            printf("%3d  %s  ", ptr->pid, ptr->taskName);
            switch(ptr->state) {
            case TASK_RUNNING:
                printf("TASK_RUNNING     %5d  ", ptr->queueTime);
                break;
            case TASK_READY:
                printf("TASK_READY       %5d  ", ptr->queueTime);
                break;
            case TASK_WAITING:
                printf("TASK_WAITING     %5d  ", ptr->queueTime);
                break;
            case TASK_TERMINATED:
                printf("TASK_TERMINATED  %5d  ", ptr->queueTime);
                break;
            }
            if(ptr->priority == 0)
                printf("L  ");
            else
                printf("H  ");
            if(ptr->timeQT == 10)
                printf("S\n");
            else
                printf("L\n");
            ptr = ptr->waitingQNext;
        }
    }
}
