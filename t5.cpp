//#include<iostream>
//#include<vector>
//#include <string>   
//#include <sstream> 
//#include <fstream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string str,strBin,strOrgn;
//	cout << "Input: "; // Prompt for input
//	getline(cin, str); 
//	for (int i = 0; i < str.size(); i++)
//	{
//		switch (str[i])
//		{
//		case ' ':
//		{
//			strBin += str.substr(i + 1);
//			i = str.size();
//			break;
//		}
//		case '0':
//		{
//			strBin += "0000";
//			break;
//		}
//		case '1':
//		{
//			strBin += "0001";
//			break;
//		}
//		case '2':
//		{
//			strBin += "0010";
//			break;
//		}
//		case '3':
//		{
//			strBin += "0011";
//			break;
//		}
//		case '4':
//		{
//			strBin += "0100";
//			break;
//		}
//		case '5':
//		{
//			strBin += "0101";
//			break;
//		}
//		case '6':
//		{
//			strBin += "0110";
//			break;
//		}
//		case '7':
//		{
//			strBin += "0111";
//			break;
//		}
//		case '8':
//		{
//			strBin += "1000";
//			break;
//		}
//		case '9':
//		{
//			strBin += "1001";
//			break;
//		}
//		case 'A':
//		{
//			strBin += "1010";
//			break;
//		}
//		case 'B':
//		{
//			strBin += "1011";
//			break;
//		}
//		case 'C':
//		{
//			strBin += "1100";
//			break;
//		}
//		case 'D':
//		{
//			strBin += "1101";
//			break;
//		}
//		case 'E':
//		{
//			strBin += "1110";
//			break;
//		}
//		case 'F':
//		{
//			strBin += "1111";
//			break;
//		}
//	}
//	}
//	int j = 0;
//	int flag = 0;
//begin:
//	ifstream in("HuffmanCode.txt");
//	while (j < strBin.size())
//	{ 
//		string line;
//		getline(in, line);
//		int sz = line.substr(2).size();
//		if (line.substr(2) == strBin.substr(j, sz))
//		{
//			strOrgn += line[0];
//			j += sz;
//			in.close();
//			goto begin;
//		}
//	}
//	in.close();
//	cout << "Output1: " << strBin << endl; // Output1, strBin is the binary string
//	cout << "Output2: " << strOrgn << endl;
//	return 0;
//}