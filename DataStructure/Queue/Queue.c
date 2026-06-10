#include "Queue.h"

//Init the queue
Queue* InitQueue()
{
    QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));
    head->data = 0;
    head->next = NULL;
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->rear = head;
    q->front = head;
    return q; 
}

//Show the Queue (from front to rear)
void ShowQueue(Queue* q)
{
    assert(q != NULL);
    QueueNode* tmp = q->front;
    if(tmp == q->rear) //empty queue
    {
        printf("NULL\n");
        return;
    }
    while(tmp != q->rear)
    {
        printf("%d ",tmp->next->data);
        tmp = tmp->next;
    }
    printf("\n");
}

//push ele in the queue
void PushQueue(Queue* q, eletype ele)
{
    assert(q != NULL);
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    q->rear->next = new_node;
    new_node->next = NULL;
    new_node->data = ele;
    q->rear = new_node;
}

//pop ele in the front and return the ele
eletype PopQueue(Queue* q)
{
    assert(q != NULL);
    QueueNode* tmp = q->front->next;
    if(tmp == NULL) //the queue is empty
    {
        return -1;
    }
    q->front->next = tmp->next;
    eletype ret = tmp->data;
    if(tmp == q->rear) // the front node is the last node
    {
        q->rear = q->front;
    }
    free(tmp);
    return ret;
}

int IsEmpty(Queue* q)
{
    if(q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}