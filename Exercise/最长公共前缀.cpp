#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<assert.h>
#include<string>
string commonPrefix(string&, string&);
//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//
//
//示例 1：
//
//输入：strs = ["flower", "flow", "flight"]
//输出："fl"
//示例 2：
//
//输入：strs = ["dog", "racecar", "car"]
//输出：""
//解释：输入不存在公共前缀。

//错点：没有想到最长公共前缀只需要选取一个基准字符串，算法时间复杂度太大
class Solution 
{
public:
    string longestCommonPrefix1(vector<string>& strs)//纵向扫描:时间O（mn)，空间O(1)
    {
        string ret;
        int j(1);
        size_t sz = strs.size();
        if (sz == 0)
        {
            return ret;
        }
        string base = strs[0];//选一个基准字符串(第一个）
        for (int i = 0; i < base.size(); i++)//遍历基准字符串中的每一个字符
        {
            char ch = base[i];//取出要匹配的字符
            for (int j = 1; j < sz; j++)//遍历其他字符串中的对应位置字符
            {
                if ( i == strs[j].size()||ch != strs[j][i])
                {
                    return ret;
                }
            }
            //第i个位置均相同，满足公共字串要求
            ret += ch;
        }
        return ret;
    }
    string longestCommonPrefix2(vector<string>& strs)//横向扫描
    {
        string ret;
        int i(0), j(1);
        size_t sz = strs.size();
        if (sz == 0)
        {
            return ret;
        }
        ret = strs[0];
        for (j = 1; j < sz; j++)//遍历所有字符串，找公共前缀的交集
        {
            ret = commonPrefix(ret, strs[j]);
        }
        return ret;
    }
};

string commonPrefix(string& str1, string& str2)
{
    string ret;
    size_t minlen = (str1.size() < (str2.size()) ? str1.size() : str2.size());
    string shstr=(str1.size() < (str2.size()) ? str1 : str2);
    for (int i = 0; i < minlen; i++)
    {
        if (str1[i] != str2[i])
        {
            ret = str1.substr(0, i);
            return ret;
        }
    }
    ret = shstr;
    return ret;
}

//int main()
//{
//    Solution s;
//    vector<string> strs = { {"flower"}, {"flow"}, {"flowight"} };
//    string ans;
//    ans = s.longestCommonPrefix2(strs);
//    cout << ans;
//    return 0;
//}