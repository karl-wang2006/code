#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int  n;
	scanf("%d", &n);
	if (n <= 1)
	{
		printf("No");
		return 0;
	}
	else if (n == 2)
	{
		printf("Yes");
		return 0;
	}
	else if (n % 2 == 0)
	{
		printf("No");
		return 0;
	}
		
	for (int i = 3; i <= (n / 2); i=i+2)
	{
		if (n % i == 0)
		{
			printf("No");
		    return 0;
		}
	}
	printf("Yes");
	return 0;
}