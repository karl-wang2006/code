#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode* BiTree;

typedef int eletype;

typedef struct QueueNode
{
    eletype data;
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
void PushQueue(Queue* q, eletype ele);

//pop ele in the front and return the ele
eletype PopQueue(Queue* q);

//determine whether the queue is empty. If empty, return 1
int IsEmpty(Queue* q);
