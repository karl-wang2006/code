#include<iostream>
#include<string>
using namespace std;

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

 

// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
class Solution 
{
public:
    int romanToInt(string s) 
    {
        int len = s.length();
        int sum = 0;
        if(len == 0)
        {
            return 0;
        }
        for(int i = 0 ; i < len ;  )
        {
           switch (s[i])
                {
                    case 'I':
                    {
                        if(i == len -1)
                        {
                            sum += 1;
                        }
                        else if(s[i+1] == 'V' || s[i+1] == 'X')
                        {
                            sum -= 1;    
                        }
                        else
                        {
                            sum += 1;
                        }
                        i++;
                        break;
                    }
                    case 'V':
                    {
                        sum += 5;
                        i++;
                        break;
                    }
                    case 'X':
                    {
                        if(i == len -1)
                        {
                            sum += 10;
                        }
                        else if(s[i+1] == 'L' || s[i+1] == 'C')
                        {
                            sum -= 10;    
                        }
                        else
                        {
                            sum += 10;
                        }
                        i++;
                        break;
                    }
                    case 'L':
                    {
                        sum += 50;
                        i++;
                        break;
                    }
                    case 'C':
                    {
                        if(i == len -1)
                        {
                            sum += 100;
                        }
                        else if(s[i+1] == 'D' || s[i+1] == 'M')
                        {
                            sum -= 100;    
                        }
                        else
                        {
                            sum += 100;
                        }
                        i++;
                        break;
                    }
                    case 'D':
                    {
                        sum += 500;
                        i++;
                        break;
                    }
                    case 'M':
                    {
                        sum += 1000;
                        i++;
                        break;
                    }
                }
        }
    return sum;
    }
    int transfer(char ch)
    {
        int ret;
        switch (ch)
        {
            case 'I':  return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
        
    }
    int method2(string s)
    {
        int sum = 0;
        int len = s.length();
        if(len == 0)
        {
            return 0;
        }
        for(int i = 0; i < len; i++)
        {
            if(i < len -1 && transfer(s[i]) < transfer(s[i+1]))
            {
                sum -= transfer(s[i]); 
            }
            else 
            {
                sum += transfer(s[i]);
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    string str;
    cout << "Please enter a string: ";
    cin >> str;
    int num = s.method2(str);
    cout << num << endl;
    return 0;
}