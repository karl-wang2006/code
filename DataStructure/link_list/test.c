#include "list.h"

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(arr)/sizeof(arr[0]);
    node* list = CreateListByArr(arr, len);
    node* last = FindKthLastNode(list,1);
    last->next = list->next; 
    // node* common = NewNode(3);
    // common->next = NewNode(4);
    // node* list1 = init_list();
    // node* list2 = init_list();
    // list1->next = NewNode(1);
    // list1->next->next = NewNode(6);
    // list1->next->next->next = common;
    // list2->next = common;
    // show_list(list1);
    // show_list(list2);
    // node* ptr = FindMiddleNode(list);
    // // ReverseListRecursively(list);
    // printf("%d\n",*(ptr->data));
    // RearrangeList0(list);
 
     printf("%d\n",*(FindLoopEntry(list)->data));
  
    return 0;
}
