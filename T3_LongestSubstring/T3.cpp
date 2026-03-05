// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
       bool is_duplicate = false;
       int sum1(0), sum2(0), flag = 0;
       int len = s.length();
       if(len == 0)
            return 0;
        int i , j;
       for(i = 0; i < len; i++)
       {
        is_duplicate = false;
            for(j = flag; j < i; j++)
            {
                if(s[j] == s[i])
                {
                    is_duplicate = true;
                    sum1 = i - flag;
                    i = j;
                    flag = j + 1;
                    sum2 = max(sum2 , sum1);
                    break;
                }
            }
         if(!is_duplicate && i == len -1)
            {
                sum1 = len - flag;
            }
       }
       return max(sum2,sum1);
    }
    int hashing(string s)
    {
        unordered_set<char> occ;
        int len = s.length();
        int right = -1;
        int ans = 0;
        for(int left = 0; left < len; left++)
        {
            if(left != 0)
            {
                occ.erase(s[left - 1]);
            }
            while (right < len - 1 && !occ.count(s[right + 1]))
            {
                occ.insert(s[right + 1]);
                right++;
                ans = max(ans,right - left + 1);
            }
        }
        return ans;
    }
}; 


int main()
{
    Solution ss;
    string s ;
    cin >> s;
    int ret = ss.lengthOfLongestSubstring(s);
    int ret2 = ss.hashing(s);
    cout << ret << " "<< ret2 << endl;
    return 0;
}