#define _CRT_SECURE_NO_WARNINGS  // Disable secure CRT function warnings (禁用CRT安全函数警告)
#include<stdio.h>                // Standard input/output header (标准输入输出头文件)
#include<assert.h>               // Assertion header for debugging (调试用断言头文件)
#include<string.h>               // String manipulation header (字符串操作头文件)
#
// Custom implementation of strncpy function
// 自定义实现strncpy函数
// Parameters:
//   des - destination string pointer (目标字符串指针)
//   src - source string pointer (源字符串指针)
//   n - maximum number of characters to copy (要复制的最大字符数)
// Return: pointer to destination string (返回目标字符串指针)
char* My_strncpy(char* des, const char* src, size_t n)
{
    assert(des && src);  // Ensure des and src are not NULL pointers (确保des和src不是空指针)
    char* ret = des;     // Save the starting address of destination (保存目标字符串起始地址)

    // Copy characters from src to des until n=0 or src ends
    // 从src复制字符到des，直到n为0或src结束
    while (n > 0 && *src != '\0')
    {
        *des = *src;
        des++;
        src++;
        n--;
    }

    // Fill remaining positions with null terminator if n > 0
    // 如果还有剩余n，用空字符填充剩余位置
    while (n > 0)
    {
        *des = '\0';
        des++;
        n--;
    }

    return ret;  // Return the starting address of destination (返回目标字符串起始地址)
}

// Custom implementation of strncat function
// 自定义实现strncat函数
// Parameters:
//   des - destination string pointer (目标字符串指针)
//   src - source string pointer (源字符串指针)
//   n - maximum number of characters to append (要追加的最大字符数)
// Return: pointer to destination string (返回目标字符串指针)
char* My_strncat(char* des, const char* src, size_t n)
{
    assert(des && src);  // Ensure des and src are not NULL pointers (确保des和src不是空指针)
    char* ret = des;     // Save the starting address of destination (保存目标字符串起始地址)

    // Move pointer to the end of destination string
    // 将指针移动到目标字符串末尾
    while (*des != '\0')
    {
        des++;
    }

    // Append characters from src to des until n=0 or src ends
    // 从src追加字符到des，直到n为0或src结束
    while (n > 0 && *src != '\0')
    {
        *des = *src;
        des++;
        src++;
        n--;
    }

    *des = '\0';  // Add null terminator at the end (在末尾添加空终止符)
    return ret;   // Return the starting address of destination (返回目标字符串起始地址)
}

// Custom implementation of strncmp function
// 自定义实现strncmp函数
// Parameters:
//   arr1 - first string to compare (第一个要比较的字符串)
//   arr2 - second string to compare (第二个要比较的字符串)
//   n - maximum number of characters to compare (要比较的最大字符数)
// Return: 
//   0 - strings are equal (字符串相等)
//   1 - arr1 is greater than arr2 (arr1大于arr2)
//  -1 - arr1 is less than arr2 (arr1小于arr2)
int My_strncmp(const char* arr1, const char* arr2, size_t n)
{
    assert(arr1 && arr2);  // Ensure arr1 and arr2 are not NULL pointers (确保arr1和arr2不是空指针)
    int ret = 0;           // Return value initialization (返回值初始化)

    // Compare characters until they differ or n=0
    // 比较字符直到字符不同或n为0
    while (*arr1 == *arr2 && n > 0)
    {
        // Return 0 if reach null terminator (both strings end)
        // 如果遇到空终止符(两个字符串都结束)，返回0
        if (*arr1 == '\0')
        {
            return 0;
        }
        arr1++;
        arr2++;
        n--;
    }

    // Return 0 if all n characters are equal
    // 如果n个字符都相等，返回0
    if (n == 0)
    {
        return 0;
    }
    // Return 1 if arr1 character is greater
    // 如果arr1字符更大，返回1
    else if (*arr1 > *arr2)
    {
        return 1;
    }
    // Return -1 if arr1 character is smaller
    // 如果arr1字符更小，返回-1
    else
    {
        return -1;
    }
}

// Custom implementation of strstr function (Naive algorithm: O(N*M))
// 自定义实现strstr函数(朴素算法：时间复杂度O(N*M))
// Parameters:
//   str - main string to search in (要搜索的主字符串)
//   sub - substring to search for (要查找的子字符串)
// Return: pointer to first occurrence of sub in str, or NULL if not found
// 返回指向str中第一次出现sub的指针，未找到则返回NULL
char* My_strstr(const char* str, const char* sub)//Naive algorithm：O(N*M) (朴素算法：时间复杂度O(N*M))
{
    const char* p = str;  // Pointer to record match start position (记录匹配起始位置的指针)
    const char* s = sub;  // Save the starting address of substring (保存子字符串起始地址)

    // Iterate through main string
    // 遍历主字符串
    while (*str != '\0')
    {
        // Find the first matching character
        // 找到第一个匹配的字符
        while (*sub != *str)
        {
            // Return NULL if reach end of main string
            // 如果到达主字符串末尾，返回NULL
            if (*str == '\0')
            {
                return NULL;
            }
            str++;
        }

        p = str;  // Record current match position (记录当前匹配位置)

        // Continue matching subsequent characters
        // 继续匹配后续字符
        while (*sub == *str)
        {
            sub++;
            str++;
            // Return match start position if substring ends
            // 如果子字符串结束，返回匹配起始位置
            if (*sub == '\0')
            {
                return (char*)p;
            }
        }

        // Move to next position and reset substring pointer
        // 移动到下一个位置并重置子字符串指针
        str = p + 1;
        sub = s;
    }

    return NULL;  // Return NULL if no match found (未找到匹配，返回NULL)
}

// KMP algorithm implementation of strstr function (empty implementation)
// KMP算法实现strstr函数(空实现)
// Parameters:
//   str - main string to search in (要搜索的主字符串)
//   sub - substring to search for (要查找的子字符串)
// Return: pointer to first occurrence of sub in str, or NULL if not found
// 返回指向str中第一次出现sub的指针，未找到则返回NULL
char* KMP_strstr(const char* str, const char* sub)
{

}

void* My_memmove(void* des, void* src, size_t num)
{
    assert(des && src);
    char* ret = des;
    if (des < src)//向前
    {
        while (num)
        {
            *(char*) des = *(char*) src;
            (char*)des = (char*)des + 1;
            (char*)src = (char*)src + 1;
            num--;
        }
    }
    else//向后
    {
        while (num)
        {
            *((char*)des + num - 1) = *((char*)src + num - 1);
            num--;
        }
    }
    return ret;
}
// Main function - program entry point
// 主函数 - 程序入口点
//int main()
//{
//    char arr1[6] = "ababc";  // Test string 1 (测试字符串1)
//    char arr2[5] = "abc";    // Test string 2 (测试字符串2)
//    // Email string for strtok test (用于strtok测试的邮箱字符串)
//    char email[100] = "wfifhionvlw@111122223333@qqqq@wwww@  nn  .  com  .  cn  .  edu";
//    char copy[100] = { 0 };  // Copy buffer for email string (邮箱字符串的拷贝缓冲区)
//    char spa[100] = "@.";    // Delimiter string for strtok (strtok的分隔符字符串)
//
//    strcpy(copy, email);     // Copy email string to avoid modifying original (拷贝邮箱字符串避免修改原字符串)
//    char* p = NULL;          // Pointer for strtok result (strtok结果指针)
//
//    // Split string using strtok with delimiters "@" and "."
//    // 使用strtok按分隔符"@"和"."分割字符串
//    //for (p = strtok(copy, spa); p != NULL; p = strtok(NULL, spa))
//    //{
//    //    printf("%s\n", p);   // Print each split part (打印每个分割后的部分)
//    //}
//    My_memmove(arr1+1, arr1 , 2);
//    printf("%s\n", arr1);
//    return 0;  // Program exit successfully (程序正常退出)
//}