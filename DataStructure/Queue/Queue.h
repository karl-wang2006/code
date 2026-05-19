#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
    QueueNode* rear; //push in
    QueueNode* front; //pop out
}Queue;

//Init the queue
Queue* InitQueue();

//Show the Queue (from front to rear)
void ShowQueue(Queue* q);

//push ele in the queue
void PushQueue(Queue* q, int ele);

//pop ele in the front and return the ele
int PopQueue(Queue* q);
