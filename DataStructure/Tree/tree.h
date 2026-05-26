#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int eletype;

typedef struct TreeNode
{
    eletype data;
    struct TreeNode* left;
    struct TreeNode* Right;
}TreeNode;

typedef TreeNode* BiTree;

//Initialize the Binary Tree
BiTree InitTree();

//give an array and create a complete binary tree
void CreateTree(eletype* arr,int n,int idx,BiTree root); 

//show the whole tree in preorder
void PreOrder(BiTree root);