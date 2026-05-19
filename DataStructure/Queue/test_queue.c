#include "Queue.h"

int main()
{
    Queue* queue = InitQueue();
    PushQueue(queue,2);
    PushQueue(queue,3);
    PushQueue(queue,4);
    PushQueue(queue,5);
    ShowQueue(queue); 
    printf("%d\n",PopQueue(queue));

    printf("%d\n",PopQueue(queue));
 
    printf("%d\n",PopQueue(queue));
 
    printf("%d\n",PopQueue(queue));
    ShowQueue(queue);
    return 0;
}