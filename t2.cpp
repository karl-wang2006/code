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
//	cout << "Enter a string: ";
//	string str,letter,sen;
//	int res;
//	getline(cin, str);
//	istringstream ss(str);
//	while (ss >> letter)
//	{
//		sen += letter;
//	}
//	for (int i = 0; i < sen.size(); i++)
//	{
//		if (sen[i] >= 'A' && sen[i] <= 'Z')
//		{
//			sen[i] = sen[i] - 'A' + 'a';
//		}
//	}
//	string ret = sen;
//	reverse(sen.begin(), sen.end());
//	if (sen == ret)
//		res = 1;
//	else
//		res = 0;
//	cout << res << endl;
//	return 0;
//}