#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

int my_strlen(char* arr)
{
	if (*arr != '\0')
		return 1 + my_strlen(arr + 1);
	else
		return 0;
}
