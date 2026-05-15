#include "stack.h"

int main()
{
    Stack* stack = InitStack();
    // printf("%d\n",IsEmptyStack(stack));
    ShowStack(stack);
    PushStack(stack,4);

    PushStack(stack,5);
    PushStack(stack,7);
    printf("%d\n",GetTopEle(stack));
    PushStack(stack,9);
    PopStack(stack);
    ShowStack(stack);
    return 0;
}