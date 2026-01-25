//#include <iostream>
//#include<vector>
//#include<sstream>
//using namespace std;

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void print2(int (*ptr)[6], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%02d ", ptr[i][j]);
		}
		printf("\n");
	}
}

int com_int(const void* e1, const void* e2)
{
	return(*(int*)e2 - *(int*)e1);
}
//int main()
//{
//	
//	return 0;
//}