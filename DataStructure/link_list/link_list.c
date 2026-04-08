#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int dataType; //semicolon!!!

typedef struct node
{
    dataType* data; //pointer of data in this node
    struct node* next; //the pointer that points to the next node
} node;

node* init_list() //initialize the first node with data 0 and NULL next
{
    node *p = (node*)malloc(sizeof(node));
    p->data = (dataType*)malloc(sizeof(dataType));
    *(p->data) = 0;
    p-> next = NULL;
    return p;
}

//print the whole list elements
void show_list(node* pc)
{
    pc = pc->next;
    while(pc != NULL) //the current node exists
    {
        printf("%d ",*(pc->data));
        //jump to the next node pointer
        pc = pc -> next;
    }
    printf("\n");
}

//get the length of linked list
size_t length(node* pc)
{
    size_t num = 0;
    pc = pc->next;//skip the head node
    while(pc != NULL)
    {
        pc = pc->next;
        num++;
    }
    return num;
}

//insert a new node after the head node 
int add_node_head(node* pc,dataType ele)
{
    assert(pc != NULL);
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = (dataType*)malloc(sizeof(dataType));
    new_node->next = pc->next;
    pc->next = new_node;
    *(new_node->data) = ele;
    return 0;
}

//add node at the tail of linked list
void  add_node_tail(node* pc,dataType ele)
{
    assert(pc != NULL);
    //find the last node
    while(pc->next != NULL) // the next node exists
    {
        pc = pc->next;
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = (dataType*)malloc(sizeof(dataType));
    pc->next = new_node; //let the new node be the next node
    *(new_node->data) = ele;
    new_node->next = NULL; //the last node's next node is empty
}

//insert ele in the position of idx(0 idx denotes the first node after the head node)
void add_node_idx(node* pc,size_t idx,dataType ele)
{
    assert(idx <= length(pc) && idx >= 0);
    assert(pc != NULL);
    for(size_t i = 0; i < idx;i++)
    {
        pc = pc->next; //walk idx steps to stop at the idx-1
    }

    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = (dataType*)malloc(sizeof(dataType));
    *(new_node->data) = ele;

    new_node->next = pc->next;
    pc->next = new_node;

}

//delete the idx of node
void del_node_idx(node* pc,size_t idx)
{
    assert(pc != NULL);
    assert(idx >= 0 && idx < length(pc));
    for(size_t i = 0;i < idx; i++)
    {
        pc = pc->next;
    }
    node* tmp = pc->next;
    pc ->next = tmp->next;
    free(tmp->data);
    free(tmp);
}

void destructor_list(node** pc)
{
    node* head = *pc;
    node* tmp = NULL;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp->data);
        free(tmp);
    }
    *pc = NULL;
}

int main()
{
    node *list = init_list(); 
    add_node_head(list,20);
    show_list(list);
    add_node_tail(list,40);
    add_node_tail(list,10);
    show_list(list);
    add_node_idx(list,3,70);
    printf("%zu\n",length(list));
    show_list(list);
    destructor_list(&list);
    return 0;
}
