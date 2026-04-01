# def isValid(s):
    # """
    # :type s: str
    # :rtype: bool
    # """
    # # 左右指针法
    # L = ['(','[','{']
    # flag = 0 # 指示未检验过的第一个元素下标
    # length = len(s)
    # if length % 2 != 0:
    #     return False #奇数个元素必然存在没有配对的
    # pair = {'(':')','{':'}','[':']'}

    # while flag < length:
    #     left = flag
    #     while left < length and s[left] in L: #一直是左括号且没有越界(短路效应：判断越界在前)
    #         left += 1
    #     if left == length: 
    #         return False # 边界条件：遍历完都没有右括号，直接结束
    #     #此时left 指向第一个右括号
    #     right = left #指向第一个右括号
    #     left -= 1 #指向最后一个左括号
    #     if left < flag:
    #         return False # 边界条件：一个左括号都没有，直接结束
    #     if left - flag > (length - 1) - right: #左括号数大于剩余括号数
    #         return False
    #     else: # 左括号数小于等于剩余括号数
    #         while left >= flag: #循环至左括号结束
    #             if s[right] == pair[s[left]]:
    #                 left -= 1
    #                 right += 1
    #             else:
    #                 return False  #任意一对不匹配
    #         flag = right #所有括号均匹配,把flag放置到未检验的地方
    # return True #flag遍历完也没有报错，就是符合要求的字符串
# 错误解法，没有考虑到栈的特性

def isValid(s): #正确解法：用栈的性质：先进后出！！！
    # 把左括号压栈，遇到匹配的右括号就弹栈
    length = len(s)
    if length % 2 == 1:
        return False #奇数个元素必然存在没有配对的
    pair = {'}':'{',']':'[',')':'('}
    stack = []
    for ch in s:
        if ch in pair: # 字符是右括号
            if not stack or stack[-1] != pair[ch]: # 空栈或栈顶元素不匹配
                return False
            else: #栈顶匹配了
                stack.pop() #弹栈
        else: # 字符是左括号
            stack.append(ch) #压栈
    return not stack

                


def main():
    test1 = "]("
    test2 = "[([])({})()]"
    test3 = "{[()]}"
    print(isValid(test1))
    print(isValid(test2))
    print(isValid(test3))

if __name__ == "__main__":
    main()
