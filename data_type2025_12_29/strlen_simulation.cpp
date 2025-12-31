#include <iostream>
using namespace std;
size_t My_strlen( const char* arr)
{
	size_t ret=0;
	if (arr == NULL)
	{
		return 0;
	}
	while (*arr)
	{
		ret++;
		arr++;
	}
	return ret;
}
