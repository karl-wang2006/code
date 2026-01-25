#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

int is_prime_number(int n)
{
	if (n == 1)
		return 0;
	else if (n % 2 == 0 && n != 2)
		return 0;
	else if (n == 2)
		return 1;
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}