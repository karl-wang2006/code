#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int binary_search(int arr[], int k, int size)
{
	int left = 0;
	int right = size - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] > k)
		{
			right = mid;
		}
		else if (arr[mid] < k)
		{
			left = mid+1;
		}
		else if (arr[mid] == k)
		{
			return mid;
		}
		if (left  == right && arr[right] != k)
			return -1;

	}

}
