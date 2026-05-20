#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

//stack with int
typedef struct Stack
{
    int data;
    struct Stack* next;
}Stack;

//stack with char
typedef struct Stack2
{
    char data;
    struct Stack2* next;
}Stack2;

typedef enum
{
    NUM, ADD, SUB, MUL, DIV, LeftP, RightP, EOS
}ContentType;

//Initialize the stack(empty)
Stack* InitStack();

//Initialize the stack2(empty)
Stack2* InitStack2();

//determine whether the stack is empty
int IsEmptyStack(Stack* head);

//determine whether the stack2 is empty
int IsEmptyStack2(Stack2* head);

//show the stack ele
void ShowStack(Stack* head);

//push an ele into the stack
void PushStack(Stack* head,int ele);

//push an char into the stack
void PushStackChar(Stack2* head,char ele);

//pop the ele out of the stack and return the popped ele
int PopStack(Stack* head);

//pop the ch out of the stack and return the popped ch
char PopStackCh(Stack2* head);

//get the top ele
int GetTopEle(Stack* head);

//get the top ch
char GetTopCh(Stack2* head);

//calculate the postfix expression in string and return the result(Only one digit)
int CalPostfix(char* str);

//return the type of the char
ContentType GetToken(char ch);

//Tranfer the infix to postfix then return the address of the first ch
char* InfixToPostfix(char* str);
