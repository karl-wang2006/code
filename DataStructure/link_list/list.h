#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int dataType; //semicolon!!!

typedef struct node
{
    dataType* data; //pointer of data in this node
    struct node* next; //the pointer that points to the next node
} node;

//initialize the first node with data 0 and NULL next
node* init_list(); 

//create a new node and return the node pointer
node* NewNode(dataType val);

// create list by array
node* CreateListByArr(const dataType arr[], int n);

//print the whole list elements
void show_list(node* pc);

//get the length of linked list
size_t length(node* pc);

//insert a new node after the head node 
int add_node_head(node* pc,dataType ele);

//add node at the tail of linked list
void  add_node_tail(node* pc,dataType ele);

//insert ele in the position of idx(0 idx denotes the first node after the head node)
void add_node_idx(node* pc,size_t idx,dataType ele);

//delete the idx of node
void del_node_idx(node* pc,size_t idx);

//destruct the list
void destructor_list(node** pc);

//Find the k-th node from the end of a linked list
node* FindKthLastNode(node* head, int k);

//find the first common node of the 2 lists, return NULL if no common node
node* FindCommonPrefix(node* head1, node* head2);

//given n-length list with abs(data)<=n. delete the repeated nodes with the same abs(data), only reserve the first-appeared node. 
void DeleteRepeatedNode(node* head, int n);

//reverse the list and return the new head node pointer
node* ReverseList(node* head);