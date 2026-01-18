#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* modif_space(char* pc,int len)
{
	assert(pc && len);
	int count = 0;
	char* ptr = pc, *p = pc;//多个指针定义不要漏了 * ！！！
	while (*ptr != '\0')
	{
		if (*ptr == ' ')
		{
			count++;
		}
		ptr++;
	}
	if (count == 0)
	{
		return p;
	}
	else
	{
		pc = ptr;
		ptr = ptr + count * 2;
	}
	while (pc >= p)
	{
		if (*pc == ' ')
		{
			*ptr = '0';
			ptr--;
			*ptr = '2';
			ptr--;
			*ptr = '%';
			ptr--;
			pc--;
		}
		else
		{
			*ptr = *pc;
			ptr--;
			pc--;
		}
	}

	return p;
}

//int main()
//{
//	char arr[70] = "Hello W or ld    You  And Me ";
//	int len = strlen(arr);
//	printf("%s",modif_space(arr,len));
//	return 0;
//}