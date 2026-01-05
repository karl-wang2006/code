#include<stdio.h>
#include<assert.h>

char* My_strncpy(char* des, const char* src, size_t n)
{
	assert(des && src);
	char* ret = des;
	while (n > 0 && *src != '\0')
	{
		*des = *src;
		des++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*des = '\0';
		des++;
		n--;
	}
	return ret;
}

char* My_strncat(char* des, const char* src, size_t n)
{
	assert(des && src);
	char* ret = des;
	while (*des != '\0')
	{
		des++;
	}
	while (n > 0 && *src != '\0')
	{
		*des = *src;
		des++;
		src++;
		n--;
	}
	*des = '\0';
	return ret;
}

int My_strncmp(const char* arr1, const char* arr2, size_t n)
{
	assert(arr1 && arr2);
	int ret = 0;
	while (*arr1 == *arr2 && n > 0)
	{
		if (*arr1 == '\0')
		{
			return 0;
		}
		arr1++;
		arr2++;
		n--;
	}
	if (n == 0)
	{
		return 0;
	}
	else if (*arr1 > *arr2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

char* My_strstr(const char* str, const char* sub)//ÆÓËØËã·¨£ºO(N*M)
{
	const char* p = str;
	const char* s = sub;
	while (*str!='\0')
	{
		while (*sub != *str)
		{
			if (*str == '\0')
			{
				return NULL;
			}
			str++;
		}
		p = str;
		while (*sub == *str)
		{
			sub++;
			str++;
			if (*sub == '\0')
			{
				return (char*)p;
			}
		}
		str = p + 1;
		sub = s;
	}
	return NULL;
}
char* KMP_strstr(const char* str, const char* sub)
{

}
int main()
{
	char arr1[6] = "ababc";
	char arr2[5] = "abc";
	//printf("%s\n", My_strncpy(arr1, arr2, 10));
	//printf("%s\n", My_strncat(arr1, arr2, 30));
	//printf("%d\n", My_strncmp(arr1, arr2,10));
	char* p = KMP_strstr(arr1, arr2);
	printf("%s\n", p);
	return 0;
}