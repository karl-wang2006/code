#include "stack.h"

//Initialize the stack(empty)
Stack* InitStack()
{
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = 0;
    p->next = NULL;
    return p;
}

Stack2* InitStack2()
{
    Stack2* p = (Stack2*)malloc(sizeof(Stack2));
    p->data = '0';
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

//determine whether the stack2 is empty
int IsEmptyStack2(Stack2* head)
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

//push an char into the stack
void PushStackChar(Stack2* head,char ele)
{
    assert(head != NULL);
    Stack2* new_ele = (Stack2*)malloc(sizeof(Stack2));
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

//pop the ch out of the stack and return the popped ch
char PopStackCh(Stack2* head)
{
    assert(head != NULL);
    if(head->next != NULL)
    {
        Stack2* tmp = head->next;
        head->next = tmp->next;
        char ret = tmp->data;
        free(tmp);
        return ret;
    }
    else
    {
        printf("Empty Stack\n");
        return 0;
    }
}

//get the top ele
int GetTopEle(Stack* head)
{
    assert(head != NULL && head->next != NULL);
    return head->next->data;
}

//get the top ch
char GetTopCh(Stack2* head)
{
    assert(head != NULL && head->next != NULL);
    return head->next->data;
}

//return the type of the char
ContentType GetToken(char ch)
{
    switch(ch)
            {
                case '+':
                {
                    return ADD;
                }
                case '-':
                {
                    return SUB;
                }
                case '*':
                {
                    return MUL;
                }
                case '/':
                {
                    return DIV;
                }
                case '(':
                {
                    return LeftP;
                }
                case ')':
                {
                    return RightP;
                }
                case 0:
                {
                    return EOS;
                }
                default:
                {
                    return NUM;
                }
            }   
}

//calculate the postfix expression in string and return the result
int CalPostfix(char* str)
{
    Stack* stack = InitStack();
    while(*str != '\0')
    {
        ContentType token = GetToken(*str);
        if(token == NUM)
        {
            PushStack(stack, *str - '0');
        }
        else
        {
            int p1 = PopStack(stack);
            int p2 = PopStack(stack);
            switch(token)
            {
                case ADD:
                {
                    PushStack(stack, p2 + p1);
                    break;
                }
                case SUB:
                {
                    PushStack(stack, p2 - p1);
                    break;
                }
                case MUL:
                {
                    PushStack(stack, p2 * p1);
                    break;
                }
                case DIV:
                {
                    PushStack(stack, p2 / p1);
                    break;
                }
            }
        }
        str++;
    }
    return PopStack(stack);
}

//Tranfer the infix to postfix then return the address of the first ch
char* InfixToPostfix(char* str)
{
    //NUM, ADD, SUB, MUL, DIV, LeftP, RightP, EOS
    int in_stack[] = {0,1,1,2,2,0,4,0};
    int out_stack[] = {0,1,1,2,2,3,4,0};
    int len = strlen(str);
    char* ret = (char*)malloc(sizeof(char)*len);
    char* tmp = ret;
    Stack2* stack = InitStack2();
    PushStackChar(stack, 0);
    while(*str != '\0')
    {
        ContentType token = GetToken(*str);
        switch(token)
        {
            case NUM:
            {
                *ret = *str;
                ret++;
                break; 
            }
            case LeftP:
            {
                PushStackChar(stack, *str);
                break;
            }
            case RightP:
            {
                while(GetTopCh(stack) != '(')
                {
                    *ret = PopStackCh(stack);
                    ret++;
                }
                PopStackCh(stack);
                break;
            } 
            case EOS:
            {
                break;
            }
            default: //operators
            {
                while(out_stack[token] <= in_stack[GetToken(GetTopCh(stack))])
                {   
                *ret = PopStackCh(stack);
                ret++;
                }

                PushStackChar(stack,*str);
            }
        }

        str++;
    }

    while(GetToken(GetTopCh(stack)) != EOS) //push all except the EOS
    {
        *ret = PopStackCh(stack);
        ret++;
    }

    *ret = '\0';
    return tmp;
}
