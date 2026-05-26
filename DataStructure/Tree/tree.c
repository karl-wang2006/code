#include "tree.h"

//Initialize the Binary Tree with the root node
BiTree InitTree()
{
    BiTree p = (BiTree)malloc(sizeof(TreeNode));
    p->data = 0;
    p->left = NULL;
    p->Right = NULL;
    return p;
}

//give an array and create a complete binary tree
//arr: the address of the first element in the array;
//n: total number in the array
//idx: the index of the element in the array
//root: current Binary Tree's tree root
//function:Put the arr[idx] into the current 'root' and create its children(left and right) recursively
void CreateTree(eletype* arr,int n,int idx,BiTree root)
{
    if(idx >= n) //the stopping point
    {
        root = NULL;
        return;
    }
    root->data = arr[idx];
    BiTree left_node = (BiTree)malloc(sizeof(TreeNode));
    BiTree right_node = (BiTree)malloc(sizeof(TreeNode));
    CreateTree(arr,n,2*idx + 1,left_node);
    root->left = left_node;
    CreateTree(arr,n,2*idx + 2,right_node);
    root->Right = right_node;
}

//show the whole tree in preorder
void PreOrder(BiTree root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->Right);
}
