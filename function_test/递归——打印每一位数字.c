#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

void print(int num)
{
	if (num > 9)
	{
		print(num / 10);
	}
	printf("%d ", num % 10);
}
