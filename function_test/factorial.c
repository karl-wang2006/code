#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

int fac(int n)
{
	if (n == 1 || n == 0)
		return 1;
	while (n >= 2)
		return n * fac(n - 1);
}