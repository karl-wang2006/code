#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。
// 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
//示例 1：
//
//输入：nums = [1, 2, 1, 3, 2, 5]
//输出：[3, 5]
//解释：[5, 3] 也是有效的答案。
//示例 2：
//
//输入：nums = [-1, 0]
//输出：[-1, 0]
//示例 3：
//
//输入：nums = [0, 1]
//输出：[1, 0]
class Solution
{
public:
    vector<int> singleNumber1(vector<int>& nums)
    {
        vector<int> ret;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < nums.size(); i++)
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
    //按位异或
    vector<int> singleNumber2(vector<int>& nums)
    {
        vector<int> ret;
        int sz = nums.size();
        int a = 0;
        for (int i = 0; i < sz; i++)//求出两个单独数的异或值
        {
            a = a ^ nums[i];
        }
        //找两个数二进制不一样的位置，把所有数字按这一位（1/0）分两类
        int pos = 0;
        for (int j = 0; j <= 31; j++)
        {
            if (((a >> j) & 1) == 1)
            {
                pos = j;
                break;
            }
        }
        //分别对两组按位异或，得到的结果就是两个单独数
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
//int main()
//{
//    Solution s;
//    vector<int> arr = { -1,-1,0,0,2,2,3,3,8,6,8,9,6,4 ,10086,-12,4,9};
//    vector<int> arr1, arr2;
//    arr1 =s.singleNumber1(arr);
//    arr2 = s.singleNumber2(arr);
//    for (auto& i : arr1)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
//    for (auto& i : arr2)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
//    return 0;
//}