#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int power3(int x)
{
	int y = 0;
	y = x * x * x;
	return y;
}
int main()
{
	int m, n, q;
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++)
	{
		q = power3(i / 100) + power3((i / 10) % 10) + power3(i % 10);
		if (q == i && q >= 100 && q <= 999)
		{
			printf("%d\n", q);
		}
	}
	return 0;
}