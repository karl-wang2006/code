#include<stdio.h>
typedef int data_type;
#define MAX 100

typedef struct 
{
    data_type data[MAX];
    int length;
} seq_list;

int init(seq_list* pc)
{
    pc->length = 0;
    return 0;
}

int print(seq_list* pc)
{
    for (int i = 0; i < pc->length; i++)
    {
        printf("%d ",pc->data[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    seq_list list;
    init(&list); //initialization
    print(&list); // print the elements in the list
    int idx = 3; int n = 5;
    // insert(&list,idx,n); // insert an element n at the index position
    return 0;
}
