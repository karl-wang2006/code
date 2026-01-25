#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

void fib(unsigned long long n)
{
	unsigned long long a = 1;
	unsigned long long b = 1;
	unsigned long long c = 1;
	if(n==1)
	printf("%d ", 1);
	else if (n == 2)
	{
		printf("%d ", 1);
		printf("%d ", 1);
	}
	else if (n >= 3)
	{
		printf("%d ", 1);
		printf("%d ", 1);
		for (int i = 1; i <= n - 2; i++)
		{
			c = a + b;
			a = b;
			b = c;
			printf("%d ", c);

		}
	}
}
