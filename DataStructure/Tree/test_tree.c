#include "tree.h"

int main()
{
    BiTree tree = InitTree();
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    CreateTree(arr,n,0,tree);
    PreOrder(tree);
    printf("\n");
    return 0;
}