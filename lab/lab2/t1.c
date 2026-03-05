#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n, m;
	scanf("%d", &n);
	m = 1;
	for (int i = 1; i <= n; i++)
	{
		m = m * i;
	}
	printf("%d", m);
	return 0;
}