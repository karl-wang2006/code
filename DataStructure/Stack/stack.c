#include "stack.h"

//Initialize the stack(empty)
Stack* InitStack()
{
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = 0;
    p->next = NULL;
    return p;
}


//determine whether the stack is empty
int IsEmptyStack(Stack* head)
{
    assert(head != NULL);
    if(head->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//show the stack ele
void ShowStack(Stack* head)
{
    assert(head != NULL);
    while(head->next != NULL)
    {
        printf("%d ", head->next->data);
        head = head->next;
    }
    printf("\n");
}

//push an ele into the stack
void PushStack(Stack* head,int ele)
{
    assert(head != NULL);
    Stack* new_ele = (Stack*)malloc(sizeof(Stack));
    assert(new_ele != NULL);
    new_ele->data = ele;
    new_ele->next = head->next;
    head->next = new_ele;
}

//pop the ele out of the stack and return the popped ele
int PopStack(Stack* head)
{
    assert(head != NULL);
    if(head->next != NULL)
    {
        Stack* tmp = head->next;
        head->next = tmp->next;
        int ret = tmp->data;
        free(tmp);
        return ret;
    }
    else
    {
        printf("Empty Stack\n");
        return -1;
    }
}

//get the top ele
int GetTopEle(Stack* head)
{
    assert(head != NULL && head->next != NULL);
    return head->next->data;
}

