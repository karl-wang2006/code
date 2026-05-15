#include "dlist.h"


Dnode* init_Dlist() //initialize the first Dnode with data 0 and NULL next
{
    Dnode *p = (Dnode*)malloc(sizeof(Dnode));
    p->data = (dataType*)malloc(sizeof(dataType));
    *(p->data) = 0;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

Dnode* NewDnode(dataType val)
{
    Dnode* p = (Dnode*)malloc(sizeof(Dnode));
    p->data = (dataType*)malloc(sizeof(dataType));
    *(p->data) = val;
    p->next = NULL;
    p->prev =NULL;
    return p;
}

//print the whole list elements
void show_Dlist(Dnode* pc)
{
    pc = pc->next; //skip the head Dnode
    while(pc != NULL) //the current Dnode exists
    {
        printf("%d ",*(pc->data));
        //jump to the next Dnode pointer
        pc = pc -> next;
    }
    printf("\n");
}

//get the length of linked list
size_t Dlength(Dnode* pc)
{
    size_t num = 0;
    pc = pc->next;//skip the head Dnode
    while(pc != NULL)
    {
        pc = pc->next;
        num++;
    }
    return num;
}

//insert a new Dnode after the head Dnode 
int add_Dnode_head(Dnode* pc,dataType ele)
{
    assert(pc != NULL);
    Dnode* new_Dnode = (Dnode*)malloc(sizeof(Dnode));
    new_Dnode->data = (dataType*)malloc(sizeof(dataType));
    new_Dnode->next = pc->next; //point the next Dnode first, or it will lose the address
    pc->next->prev = new_Dnode;
    pc->next = new_Dnode;
    new_Dnode->prev = pc;
    *(new_Dnode->data) = ele;
    return 0;
}

//add Dnode at the tail of linked list
void  add_Dnode_tail(Dnode* pc,dataType ele)
{
    assert(pc != NULL);
    //find the last Dnode
    while(pc->next != NULL) // determine whether the next Dnode exists(the premise is the current Dnode is not empty)
    {
        pc = pc->next;
    }
    Dnode* new_Dnode = (Dnode*)malloc(sizeof(Dnode));
    new_Dnode->data = (dataType*)malloc(sizeof(dataType));
    pc->next = new_Dnode; //let the new Dnode be the next Dnode
    new_Dnode->prev = pc;
    *(new_Dnode->data) = ele;
    new_Dnode->next = NULL; //the last Dnode's next Dnode is empty
}

//insert ele in the position of idx(0 idx denotes the first Dnode after the head Dnode)
void add_Dnode_idx(Dnode* pc,size_t idx,dataType ele)
{
    assert(idx <= Dlength(pc) && idx >= 0);
    assert(pc != NULL);
    for(size_t i = 0; i < idx;i++)
    {
        pc = pc->next; //walk idx steps to stop at the idx-1
    }

    Dnode* new_Dnode = (Dnode*)malloc(sizeof(Dnode));
    new_Dnode->data = (dataType*)malloc(sizeof(dataType));
    *(new_Dnode->data) = ele;


    new_Dnode->next = pc->next;
    new_Dnode->prev = pc;
    pc->next->prev = new_Dnode;
    pc->next = new_Dnode;

}

//delete the idx of Dnode
void del_Dnode_idx(Dnode* pc,size_t idx)
{
    assert(pc != NULL);
    assert(idx >= 0 && idx < Dlength(pc));
    for(size_t i = 0;i < idx; i++)
    {
        pc = pc->next;
    }

    Dnode* tmp = pc->next;
    pc->next = tmp->next;
    if(pc->next != NULL)// need to check that the last node
    {
        pc->next->prev = pc;
    }

    free(tmp->data);
    free(tmp);
}


void destructor_Dlist(Dnode** pc)// use double pointer to make *list empty
{
    assert(pc != NULL);
    Dnode* head = *pc;
    Dnode* tmp = NULL;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp->data);
        free(tmp);
    }
    *pc = NULL;
}

Dnode* CreateDlistByArr(const dataType arr[], int n)
{
    // initialize the head node
    Dnode* head = init_Dlist();
    for (int i = 0; i < n; i++)
    {
        add_Dnode_tail(head, arr[i]);
    }
    return head;
}
