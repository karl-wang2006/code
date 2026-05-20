#include "stack.h"

int main()
{
    Stack* stack = InitStack();
    char test[] = "((5+6)-3)*(8/4)-(((3+7)-2/1)*2+9)";
    printf("%s\n",InfixToPostfix(test));
    printf("%d\n",CalPostfix(InfixToPostfix(test)));
    return 0;
}