#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

void find_num(int n)
{

	for (int i = 2; i <= (n + 1) / 2; i++)
	{	
		if (n % i == 0)
		{
			printf("%d x ",i);
		}
		else if (n == 1)
			return;
		find_num(n / i);
	}
}

