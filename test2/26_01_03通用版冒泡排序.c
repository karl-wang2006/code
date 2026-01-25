#include <stdio.h>
#include<string.h>
struct stu
{
	char name[100];
	int age;
};

void bubble_sort(int arr[],int sz)
{
	if (sz <= 1)
	{
		return;
	}
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void Swap(char* p1, char* p2, size_t size)
{
	for (size_t j = 0; j < size; j++)
	{
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2++;
	}
	return;
}

void general_bubble_sort(const void* base, size_t num,size_t size,
	int (*compare)(const void* e1,const void* e2))
//pointer to comparing function
{
	if (num <= 1)
	{
		return;
	}
	for (size_t i = 0; i < num - 1; i++)
	{
		int flag = 1;
		for (size_t j = 0; j < num - 1 - i; j++)
		{
			if (compare((char*)base+j*size,(char*)base+(j+1)*size) > 0)
			{
				Swap((char*)base + j * size, (char*)base + (j + 1) * size , size);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return(*(int*)e1 - *(int*)e2);
}
int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
int main()
{
	int  arr[] = { 1,1312,15,4 ,2354,3,2,-244,-2542351,0,-1};
	struct stu s[] = { {"zhangsan",15},{"lisi",20},{"wangwu",25} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int size = sizeof(s) / sizeof(s[0]);
	general_bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	general_bubble_sort(s, size , sizeof(s[0]) , cmp_stu_name);
	for (int j = 0; j < sz; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
	for (int j = 0; j < size; j++)
	{
		printf("%s %d\n", s[j].name, s[j].age);
	}
	return 0;
}
