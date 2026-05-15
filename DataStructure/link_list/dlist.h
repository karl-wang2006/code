#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int dataType; 

typedef struct Dnode
{
    dataType* data; //pointer of data in this Dnode
    struct Dnode* next; //the pointer that points to the next Dnode
    struct Dnode* prev; //the pointer that points to the previous Dnode
} Dnode;

//initialize the first Dnode with data 0 and NULL next
Dnode* init_Dlist(); 

//create a new Dnode and return the Dnode pointer
Dnode* NewDnode(dataType val);

// create list by array
Dnode* CreateDlistByArr(const dataType arr[], int n);

//print the whole list elements
void show_Dlist(Dnode* pc);

//get the length of linked list
size_t Dlength(Dnode* pc);

//insert a new Dnode after the head Dnode 
int add_Dnode_head(Dnode* pc,dataType ele);

//add Dnode at the tail of linked list
void add_Dnode_tail(Dnode* pc,dataType ele);

//insert ele in the position of idx(0 idx denotes the first Dnode after the head DDnode)
void add_Dnode_idx(Dnode* pc,size_t idx,dataType ele);

//delete the idx of node
void del_Dnode_idx(Dnode* pc,size_t idx);

//destruct the list
void destructor_Dlist(Dnode** pc);
