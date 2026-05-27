#include "tree.h"



int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    BiTree tree = CreateThrTree(arr,n,0);
    InorderThreadTraverse(tree);//8 4 2 5 1 6 3 7
    BiTree p = GetInorderPredecessor(tree->Right);
    BiTree q = GetInorderSuccessor(tree->Right);
    printf("%d\n",p->data);//3
    printf("%d\n",q->data);//head
    return 0;
}