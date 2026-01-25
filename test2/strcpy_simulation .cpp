#include <iostream>
using namespace std;

char*  My_strcpy(const char* tag,char* ret,int n)
{
	if (ret == NULL || tag == NULL)
	{
		return NULL;
	}
	char* origin = ret;
	for (int i = 0; i < n; i++)
	{
		if (!(*tag))
		{
			*ret = '\0';
			return origin;
		}
		*ret = *tag;
		ret++;
		tag++;
	}
	*ret = '\0';
	return origin;
}

