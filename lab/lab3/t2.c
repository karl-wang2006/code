#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
 
int main()
{ 
	int dot = 0;
	int j = 0;
	int idx = 0;
	char str[100];
	char result[100];
	scanf("%s", str);
	int len = strlen(str);
	for (dot = 0; dot <= len - 1; dot++)
	{
		if (str[dot] == '.')
			break;
		else if (dot == len - 1)
		{
			printf("%s", str);
			return 0;
		}
	}
	char integer[100] = { 0 };
	char decimal[100] = { 0 };
	for (int k = 0; k < dot; k++)
	{
		integer[k] = str[k];
	}
	integer[dot] = '\0';
	strncpy(decimal, str + dot + 1, len - 1- dot );
	int last_non_zero = len - 1 - dot - 1;
	while (last_non_zero >= 0 && decimal[last_non_zero] == '0') 
		last_non_zero--;
		if (last_non_zero == -1)
		{
			printf("%s", integer);
			return 0;
		}
		decimal[last_non_zero + 1] = '\0';
		strcpy(result, integer);
	    strcat(result, ".");
		strcat(result, decimal);
		printf("%s", result);
		return 0;
}