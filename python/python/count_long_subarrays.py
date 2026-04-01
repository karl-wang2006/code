def count_long_subarrays(s):
    num = []
    j = 0
    if len(s) == 1:
        return 1
    for i in range(1,len(s)):
        if s[i] > s[i-1]:
            continue
        elif s[i] < s[i-1]:
            num.append(i - j)
            j = i
    num.append(len(s) - j)
    return max(num)

def main():
    import sys
    test = (5,4,3,6,7,8,9)
    print(count_long_subarrays(test))
    
if __name__ == '__main__':
    main()