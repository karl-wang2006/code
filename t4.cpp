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
//	  string str,strBin,strHex;
//     cout << "Input: ";
//	 getline(cin, str);
//	 for (auto j : str)
//	 {
//		 ifstream in("HuffmanCode.txt");
//		 while (true)
//		 {
//			 string line;
//			 getline(in, line);
//			 if (line[0] == j)
//			 {
//				 strBin += line.substr(2);
//				 break;
//			 }
//		 }
//		 in.close();
//	 }
//	 int i = 0;
//	 while (true)
//	 {
//		 string digit =strBin.substr(i, 4);
//		 if (digit.size() < 4 && i != 0)
//		 {
//			 strHex += " ";
//			 strHex += digit;
//			 break;
//		 }
//		 else if (digit.size() < 4 && i == 0)
//		 {
//			 strHex += digit;
//			 break;
//		 }
//		 i += 4;
//		 int num = (digit[0] - '0') * 8 + (digit[1] - '0') * 4 + (digit[2] - '0') * 2 + (digit[3] - '0') * 1;
//		 switch (num)
//		 {
//		 case 10:
//		 {
//			 strHex += "A";
//			 break;
//		 }
//		 case 11:
//		 {
//			 strHex += "B";
//			 break;
//		 }
//		 case 12:
//		 {
//			 strHex += "C";
//			 break;
//		 }
//		 case 13:
//		 {
//			 strHex += "D";
//			 break;
//		 }
//		 case 14:
//		 {
//			 strHex += "E";
//			 break;
//		 }
//		 case 15:
//		 {
//			 strHex += "F";
//			 break;
//		 }
//		 default:
//		 {
//			 strHex += (num + '0');
//		 }
//		 }
//	 }
//	 cout << "Output1: " << strBin << endl; // Output1, strBin is the binary string
//	 cout << "Output2: " << strHex << endl;
//	return 0;
//}