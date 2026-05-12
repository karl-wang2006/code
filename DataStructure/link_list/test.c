#include "list.h"

int main()
{
    int arr[] = {1,2,3,-5,5,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    node* list = CreateListByArr(arr, len);

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
    // node* ptr = FindCommonPrefix(list1,list2);
    ReverseList(list);
    // printf("%d\n",*(ptr->data));
    show_list(list);
    
    return 0;
}
