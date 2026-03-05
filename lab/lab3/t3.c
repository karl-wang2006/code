#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>


void str_add(char* arr1, char* arr2,int len1,int len2,char*result)
{
	int n, k;
	n = 0;
	k = 0;
	int i = 0;
	int  big = (len1 >= len2 ? len1 : len2);
	int small = (len1 >= len2 ? len2 : len1);
	int arr[100] = { 0 };
	char* arrlong ;
	int idx = 0;
	if (len1 >= len2)
		arrlong = arr1;
	else
		arrlong = arr2;
	for ( i = 0; i < big; i++)
	{	
		if (i <= small - 1)
		{
			k = n + (*(arr1 + len1 - 1 - i) - '0') + (*(arr2 + len2 - 1 - i) - '0');
			if (k >= 10)
			{
				arr[i] = k % 10;
				n = 1;
			}
			else
			{
				arr[i] = k;
				n = 0;
			}
		}
		else if (i > small - 1)
		{
			k = n + (*(arrlong + big - 1 - i) - '0') + 0;
			if (k >= 10)
			{
				arr[i] = k % 10;
				n = 1;
			}
			else
			{
				arr[i] = k;
				n = 0;
			}
		}
		
	}
    if ( n == 1)
     {
	    arr[big] = 1;
        for (int j = big; j >= 0; j--) 
	    {
		result[idx] = arr[j] + '0';
		idx++;
	    }
	    result[idx] = '\0'; 
     }
	else if( n==0)
	{
		for (int j = big - 1; j >= 0; j--)
		{
			result[idx] = arr[j] + '0';
			idx++;
		}
		result[idx] = '\0';
	}
}

int main()
{
	char arr1[100];
	char arr2[100];
	scanf("%s %s", &arr1, &arr2);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	char result[100];
	str_add(arr1, arr2,len1,len2,result);
	printf("%s", result);
    return 0;
}