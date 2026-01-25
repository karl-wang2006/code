#include <iostream>
using namespace std;

void sort(int arr[],int sz)
{
	if (sz <= 1) 
	{
		return; // 边界情况：空数组或只有一个元素，无需排序
	}
	int* left = arr;
	int* right = arr+sz-1;
	while (left < right)
	{
		while ((left < right ) && (*left % 2 == 1))//保证left指针在遇到偶数时停下来,且保证指针不会越界
		{
			left++;
		}
		while ((left < right) && (*right % 2 == 0))//同理
		{
			right--;
		}
		if (left < right)//保证左右指针不交叉情况下才换
		{
			int temp = *left;
			*left = *right;
			*right = temp;
			left++;
			right--;//跳到下一对奇偶数
		}
	}
}
