#include "tree.h"


//prev records the previous node
BiTree prev;

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
    //when idx >= n, the rucursive step stops
    if(idx >= n) 
    {
        root->left = NULL;
        root->Right = NULL;
        return;
    }
    root->data = arr[idx];

    //create new tree node iff it has children
    if(2*idx + 1 < n)
    {
        BiTree left_node = (BiTree)malloc(sizeof(TreeNode));
        CreateTree(arr,n,2*idx + 1,left_node);
        root->left = left_node;
    }
    else
    {
        root->left = NULL;
    }
    
    if(2*idx + 2 < n)
    {
        BiTree right_node = (BiTree)malloc(sizeof(TreeNode));
        CreateTree(arr,n,2*idx + 2,right_node);
        root->Right = right_node;
    }
    else
    {
        root->Right = NULL;
    }
    
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

//show the whole tree in inorder
void InOrder(BiTree root)
{
    if(root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->Right);
}

//show the whole tree in postorder
void PostOrder(BiTree root)
{
    if(root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->Right);
    printf("%d ",root->data);
}

//add a head node for the tree, return the head node. 
BiTree AddHead(BiTree root)
{
    assert(root != NULL);
    BiTree head = (BiTree)malloc(sizeof(TreeNode));
    head->left = root; //left points to the begining node
    head->Right = head; //right points to itself
    head->ltag = 0;
    head->rtag = 1;
    return head;
}

void InitTags(BiTree root)
{
    if (root == NULL) return;

    // set the tag to 0 for the current node
    root->ltag = 0;
    root->rtag = 0;

    // tag recurrsively
    InitTags(root->left);
    InitTags(root->Right);
}

//In-Order threading(p is the root node)
void Threading(BiTree p)
{
    //set the boundary
    if(p == NULL)
    {
        return;
    }

    //thread the left tree first
    Threading(p->left);

    //connect p with the prev node
    if(p->left == NULL)
    {
        p->left = prev;
        p->ltag = 1;
    }

    if(prev->Right == NULL)
    {
        prev->Right = p;
        prev->rtag = 1;
    }

    //renew the prev node
    prev = p;

    //thread the right tree
    Threading(p->Right);
}


void InorderThread(BiTree head)
{
    //put the previous node be head node
    prev = head;

    //do threading from the root node
    Threading(head->left);

    //now connect the head node with the last node(prev)
    head->Right = prev;
    prev->Right = head;
    prev->rtag = 1;
    
}

// Traverse the in-order threaded binary tree
void InorderThreadTraverse(BiTree head)
{
    //initialize the pointer to the root
    BiTree p = head->left;

    //iterating
    while(p != head)
    {
        //going left until ltag is thread(1)
        while(p->ltag == 0)
        {
            p = p->left;
        }

        printf("%d ",p->data);

        //if right tag is thread and the next node is not head node, jump to the next node and print data
        while(p->rtag == 1 && p->Right != head)
        {
            p = p->Right;
            printf("%d ",p->data);
        }

        //else go to the right children
        p = p->Right;

    }
    printf("\n");
}


BiTree GetInorderSuccessor(BiTree p)
{
    assert(p != NULL);

    if(p->rtag == 1)
    {
        return p->Right;
    }
    else
    {
        p = p->Right;
        while(p->ltag == 0)
        {
            p = p->left;
        }
        return p;
    }
}   


BiTree GetInorderPredecessor(BiTree p)
{
    assert(p != NULL);
    if(p->ltag == 1)
    {
        return p->left;
    }
    else
    {
        p = p->left;
        while(p->rtag == 0)
        {
            p = p->Right;
        }
        return p;
    }
}

BiTree CreateThrTree(eletype* arr,int n,int idx)
{
    BiTree root = InitTree();
    CreateTree(arr,n,idx,root);

    //transfer the normal tree to the Threaded Binary Tree

    //give the tag all 0
    InitTags(root);

    //add head node for the tree
    BiTree head = AddHead(root);

    // 中序线索化（核心）
    InorderThread(head);

    return head;
}

//Given the root node, traverse the binary tree and print the ele by level order
// void LevelOrderTraverse(BiTree root)
// {   
//     if(root == NULL)
//     {
//         return;
//     }
//     Queue* q = InitQueue();
//     PushQueue(q, root);
//     while(!IsEmpty(q))
//     {
//         BiTree tmp = PopQueue(q);
//         printf("%d ",tmp->data);

//         if(tmp->left != NULL)
//         {
//             PushQueue(q, tmp->left);
//         }

//         if(tmp->Right != NULL)
//         {
//             PushQueue(q, tmp->Right);
//         }

//     }
//     printf("\n");
// }