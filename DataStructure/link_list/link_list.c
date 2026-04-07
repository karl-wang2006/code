#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int dataType; //semicolon!!!

typedef struct node
{
    dataType *data; //pointer of data in this node
    struct node *next; //the pointer that points to the next node
} node;

node* init_list() //initialize the first node with data 0 and NULL next
{
    node *p = (node*)malloc(sizeof(node));
    p->data = 0;
    p-> next = NULL;
    return p;
}

int add_node_head(node* pc,dataType ele)
{
    assert(pc != NULL);
    //add heret
    return 0;
}

void destructor_list(node* pc) //need fixing
{
    node* tmp = NULL;
    while (pc->next != NULL)
    {
        tmp = pc->next;
        free(pc->next);
        free(pc->data);
    }
}
int main()
{
    node *list = init_list(); 
    add_node_head(&list,20);
    show_list(&list);
    add_node_tail(&list , 10);
    show_list(&list);
    return 0;
}