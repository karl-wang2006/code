#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
// #include "../Queue/Queue.h"

typedef int eletype;

typedef struct TreeNode
{
    eletype data;
    int ltag;// 0: lchildren; 1: previous node
    int rtag;// 0: rchildren; 1: next node
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

//show the whole tree in inorder
void InOrder(BiTree root);

//show the whole tree in postorder
void PostOrder(BiTree root);

//add a head node for the tree, return the head node
BiTree AddHead(BiTree root);

//initialize all the tag to be 0(all children)
void InitTags(BiTree root);

//Convert an ordinary binary tree into an in-order threaded binary tree
void InorderThread(BiTree root);

// Traverse and show the in-order threaded binary tree
void InorderThreadTraverse(BiTree head);

// Find the successor of the in-order threaded binary tree node p
BiTree GetInorderSuccessor(BiTree p);

// find the predecessor of the in-order threaded binary tree node p
BiTree GetInorderPredecessor(BiTree p);

//give an array and create a complete binary In-order threaded tree from the beginning of index of array. Return the head node.
BiTree CreateThrTree(eletype* arr,int n,int idx);

//Given the root node, traverse the binary tree and print the ele by level order
void LevelOrderTraverse(BiTree root);