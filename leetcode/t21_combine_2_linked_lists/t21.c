#include<stdio.h>
struct ListNode 
{
    int val;
    struct ListNode *next;
};
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));//创建虚拟节点
    dummy->next = NULL;
    struct ListNode* cur = dummy;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val <= list2-> val)
        {
            cur->next = list1;//直接把节点接过来
            list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if (list1 != NULL)
    {
        cur->next = list1;
    }
    if (list2 != NULL)
    {
        cur->next = list2;
    }
    return dummy->next;//真实链表从虚拟节点的下一个开始
}