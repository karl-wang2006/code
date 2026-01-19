#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<assert.h>
#include<string>

//给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，
// 使每个元素只出现一次，返回删除后数组的新长度。元素的 相对顺序应该保持一致。
// 然后返回 nums 中唯一元素的个数。
//考虑 nums 的唯一元素的数量为 k。去重后，返回唯一元素的数量 k
//nums 的前 k 个元素应包含 排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略。
//
//判题标准 :
//系统会用下面的代码来测试你的题解:
//int[] nums = [...]; // 输入数组
//int[] expectedNums = [...]; // 长度正确的期望答案
//int k = removeDuplicates(nums); // 调用
//
//assert k == expectedNums.length;
//for (int i = 0; i < k; i++) {
//    assert nums[i] == expectedNums[i];
//}
//如果所有断言都通过，那么您的题解将被 通过。
//
//
//
//示例 1：
//
//输入：nums = [1, 1, 2]
//输出：2, nums = [1, 2, _]
//解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
//示例 2：
//
//输入：nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//输出：5, nums = [0, 1, 2, 3, 4, _, _, _, _, _]
//解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
//
//
//提示：
//
//1 <= nums.length <= 3 * 104
//- 100 <= nums[i] <= 100
//nums 已按 非递减 顺序排列。

class Solution 
{
public:
    int removeDuplicates1(vector<int>& nums)//对于任意数组，O(n^2)
    {
        int count = 0;
        int sz = nums.size();
        int flag = 0,idx = 0;//flag标记是否是重复数字，idx指示填充的下标
        for (int i = 0; i < sz; i++)
        {
            flag = 0;//必须在每一次新的判断前恢复！
            for (int j = 0; j < idx; j++)
            {
                if (nums[j] == nums[i])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)//非重复数字
            {         
               nums[idx] = nums[i];
               idx++;
               count++;
            }
            else//重复数字
            {
                //直接进入下一次循环
            }
        }
        return count;
    }
    int removeDuplicates2(vector<int>& nums)//针对递增数组，O(n)
    {
        int count = 1;
        int sz = nums.size();
        if (sz == 0)
        {
            return sz;
        }
        else if (sz == 1)
        {
            return 1;
        }
        int idx = 1;//idx指示填充的下标
        for (int i = 1; i < sz; i++)
        {
            if (nums[i - 1] != nums[i])//跟前一个不重复
            {
                nums[idx] = nums[i];
                idx++;
                count++;
            }
        }
        return count;
    }
};

//int main()
//{
//    Solution s;
//    vector<int> nums = { 0,1,1,1,2,2,3,4,7,7,8,9,9};
//    int sz = nums.size();
//    sz = s.removeDuplicates2(nums);
//    for (int i=0;i<sz;i++)
//    {
//        cout << nums[i] << " ";
//    }
//    cout <<'\n'<< sz;
//    return 0;
//}