#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<assert.h>


enum status
{
    Invalid,
	Valid
};

status sta = Invalid;

int My_atoi(const char* pc)
{
	sta = Invalid;
	if (pc == NULL)
	{
		return 0;
	}
	int flag = 1;
	while (*pc == ' ')
	{
		pc++;
	}
	if (*pc == '\0')
	{
		return 0;
	}
	if (*pc == '+')
	{
		flag = 1;
		pc++;
	}
	else if (*pc == '-')
	{
		flag = -1;
		pc++;
	}
	long long ret = 0;
	while (*pc != '\0')
	{
		if (*pc < '0' || *pc>'9')
		{
			return flag*ret;
		}
		//从前向后计算
		ret = ret * 10 + (*pc - '0');
		pc++;
		if (flag==1 && ret > INT_MAX)
		{
			return INT_MAX;
		}
		else if (flag==-1 && ret > (long long)INT_MAX + 1)
		{
			return INT_MIN;
		}
	}
	sta = Valid;
	return (int)flag*ret;
}

//int main()
//{
//	char arr[200] = "+46346";
//	cout<< sta << ":" << My_atoi(arr);
//	return 0;
//}