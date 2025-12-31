#include<iostream>
#include<vector>
#include <string>   
#include <sstream> 
#include <fstream>
#include <algorithm>
using namespace std;

class IntSet
{
private:
	int data[100];
	int size;
public:
	IntSet()
	{
		size = 0;
	}// you need to introduce a constructor

	void add(int val)
	{
		if (size + 1 > 100)
		{
			cout << "overflow" << endl;
			return;
		}
		for (int i=0;i < size;i++)
		{
			if (data[i] == val)
			{
				return;
			}
		}
		data[size] = val;
		size++;
	}

	void remove(int val)
	{
		for (int i =0;i<size;i++)
		{
			if (val == data[i])
			{
				for (int j = i; j < size; j++)
				{
					data[j] = data[j + 1];
				}
				size--;
				return;
			}
		}
		return;
		// implement this member function
		// remove element val if it exists; otherwise do nothing
	}

	void print()
	{
		cout << "The set has " << size << " elements:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << " " << data[i];
		}
		cout << endl;
	}
};

int main()
{
	IntSet s; // empty set
	s.add(10); // s becomes a set of one element, which is 10.
	s.add(20);
	s.add(10); // 10 should not be added this time.
	s.remove(20); // element 20 is removed.
	s.add(23);
	s.remove(15);
	s.print();

	return 0;

}
