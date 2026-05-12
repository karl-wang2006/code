//链表可以想象成一张张卡片的链接。一张卡片代表一个节点，记录了数据地址和下一张卡片的地址
//一个节点由data指针和指向下一个节点（卡片）的指针构成。一个链表拿到的是一个指向头节点的指针，
//头节点不算在链表的长度中
//要访问数据域，必须通过上一个节点的指针访问，自己的节点指针是访问不了自己的数据域的
//链表访问数据需要顺序遍历，没有办法像顺序表那样直接读取下标访问，好处是不需要连续的内存空间存储，
//且添加/删除元素时只需删除单个节点，不需要整体移动数据
//区分 pc != NULL 与 pc->next != NULL ,pc是形参，指示目前节点，给pc赋值不能修改链表结构。pc->next才能修改链表链接
#include "list.h"


node* init_list() //initialize the first node with data 0 and NULL next
{
    node *p = (node*)malloc(sizeof(node));
    p->data = (dataType*)malloc(sizeof(dataType));
    *(p->data) = 0;
    p-> next = NULL;
    return p;
}

node* NewNode(dataType val)
{
    node* p = (node*)malloc(sizeof(node));
    p->data = (dataType*)malloc(sizeof(dataType));
    *(p->data) = val;
    p->next = NULL;
    return p;
}

//print the whole list elements
void show_list(node* pc)
{
    pc = pc->next; //skip the head node
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
    new_node->next = pc->next; //point the next node first, or it will lose the address
    pc->next = new_node;
    *(new_node->data) = ele;
    return 0;
}

//add node at the tail of linked list
void  add_node_tail(node* pc,dataType ele)
{
    assert(pc != NULL);
    //find the last node
    while(pc->next != NULL) // determine whether the next node exists(the premise is the current node is not empty)
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


void destructor_list(node** pc)// use double pointer to make *list empty
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

node* CreateListByArr(const dataType arr[], int n)
{
    // initialize the head node
    node* head = init_list();
    for (int i = 0; i < n; i++)
    {
        add_node_tail(head, arr[i]);
    }
    return head;
}

//Find the k-th node from the end of a linked list
node* FindKthLastNode(node* head, int k)
{
    node* Fast = head;
    node* Slow = head;

    //let the fast pointer go k steps first
    for(int i = 0; i < k; i++)
    {
        Fast = Fast->next;
    }
    //fast and slow pointer go together until fast is NULL
    while(Fast != NULL)
    {
        Fast = Fast->next;
        Slow = Slow->next;
    }
    return Slow;
}

//find the first common node of the 2 lists, return NULL if no common node
node* FindCommonPrefix(node* head1, node* head2)
{
    node* fast = NULL;
    node* slow = NULL;
    int len1 = length(head1);
    int len2 = length(head2);
    int d = 0;
    if (len1 >= len2)
    {
        d = len1 - len2;
        fast = head1;
        slow = head2;
    }
    else
    {
        d = len2 - len1;
        fast = head2;
        slow = head1;
    }
    for(int i = 0; i < d; i++)
    {
        fast = fast->next;
    }
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

//given n-length list with abs(data)<=n. 
//delete the repeated nodes with the same abs(data), only reserve the first-appeared node. 
void DeleteRepeatedNode(node* head, int n)
{ 
    dataType arr[n+1];
    for(int i = 0; i < n + 1 ; i++)
    {
        arr[i] = 0;
    } 
    //iterate the whole list
    while(head->next != NULL)
    {
        int num = abs(*(head->next->data));
        if (arr[num] == 0) //first-appeared
        {
            arr[num] += 1;
            head = head->next;
        }
        else //not first-appeared
        {
            node* tmp = head->next;
            head->next = tmp->next;
            free(tmp->data);
            free(tmp);
        }
    }
}

//reverse the list and return the new head node pointer
node* ReverseList(node* head)
{
    //use 3 pointers, 2 cannot find the next
    if (head == NULL) 
    {
        return NULL;
    }
    if (head->next == NULL) 
    {
    return head;
    }
    node* p1 = NULL;
    node* p2 = head->next;
    node* p3 = p2->next;
    while(p3 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    head->next = p2;
    return head;
}