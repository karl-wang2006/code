#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber1(vector<int>& nums)
    {
        vector<int> ret;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i != sz - 1 && nums[i] == nums[i + 1])
            {
                i++;
                continue;
            }
            else
            {
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
 
    vector<int> singleNumber2(vector<int>& nums)
    {
        vector<int> ret;
        int sz = nums.size();
        int a = 0;
        for (int i = 0; i < sz; i++)
        {
            a = a ^ nums[i];
       }
     
        int pos = 0;
        for (int j = 0; j <= 31; j++)
        {
            if (((a >> j) & 1) == 1)
            {
                pos = j;
                break;
            }
        }
    
        int n1(0), n2(0);
        for (int j = 0; j < sz; j++)
        {
            if ((nums[j]>>pos) & 1 )
            {
                n1 = n1 ^ nums[j];
            }
            else
            {
                n2 = n2 ^ nums[j];
            }
        }
        ret.push_back(n1);
        ret.push_back(n2);
        return ret;
    }
};

int main()
{
   Solution s;
   vector<int> arr = { -1,-1,0,0,2,2,3,3,8,6,8,9,6,4 ,10086,-12,4,9};
   vector<int> arr1, arr2;
   arr1 =s.singleNumber1(arr);
   arr2 = s.singleNumber2(arr);
   for (auto& i : arr1)
   {
       cout << i << " ";
   }
   cout << endl;
   for (auto& i : arr2)
   {
       cout << i << " ";
   }
   cout << endl;
   return 0;
}