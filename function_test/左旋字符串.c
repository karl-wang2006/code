#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>

//普通版，O(k*n)
char* left_reverse1(char* arr,size_t k)
{
	assert(arr);
	char* ret = arr;
	while (k--)
	{
		char ch = *arr;
		for ( ; *(arr+1)!='\0' ; arr++)
		{
			*arr = *(arr + 1);
		}
		*arr = ch;
		arr = ret;
	}
	return ret;
}
void reverse(char arr[], size_t begin, size_t end)
{
	char* right = arr + end;
	char* left = arr + begin;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
//三次反转，O（n)
char* left_reverse2(char* arr, size_t k)
{
	assert(arr);
	char* ret = arr;
	size_t len = strlen(arr);
	if (len==0)
	{
		return ret;
	}
	k = k % len;
	if (len == 1 || k == 0)
	{
		return ret;
	}
	reverse(arr,0, k-1);
	reverse(arr,k, len-1);
	reverse(arr,0 ,len-1);
	return ret;
}

//普通版的递归
//左旋k次=左旋1次+左旋（k-1）次
char* left_reverse3(char* arr, size_t k)
{
	assert(arr);
	char* ret = arr;
	size_t len = strlen(arr);
	if (len == 0)
	{
		return arr;
	}
	k = k % len;
	if (k == 0 || len <= 1)
	{
		return arr;
	}
	char ch = *arr;

	for (; *(arr + 1) != '\0'; arr++)
	{
		*arr = *(arr + 1);
	}
	*arr = ch;
	arr = ret;

	left_reverse3(arr, k - 1);
	return ret;
}
