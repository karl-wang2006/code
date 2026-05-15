#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack* next;
}Stack;

//Initialize the stack(empty)
Stack* InitStack();

//determine whether the stack is empty
int IsEmptyStack(Stack* head);

//show the stack ele
void ShowStack(Stack* head);

//push an ele into the stack
void PushStack(Stack* head,int ele);

//pop the ele out of the stack and return the popped ele
int PopStack(Stack* head);

//get the top ele
int GetTopEle(Stack* head);