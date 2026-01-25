//#include <iostream>
//#include<vector>
//#include<sstream>
//using namespace std;
//
//int main()
//{
//    string str;
//    vector<int> arr;
//    getline(cin, str);
//    istringstream ss(str);
//    int num;
//    while (ss >> num)
//    {
//        arr.push_back(num);
//    }
//    int target = arr.back();
//    arr.pop_back();
//    for (int i = 0; i < arr.size(); i++)
//    {
//        for (int j = i + 1; j < arr.size(); j++)
//        {
//            if (arr[i] + arr[j] == target)
//            {
//                cout << "[" << i << "," << j << "]" << endl;
//            }
//        }
//    }
//    return 0;
//}