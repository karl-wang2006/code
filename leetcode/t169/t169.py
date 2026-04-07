def majorityElement(nums): # 输入一个数组，输出只有1个出现次数超过n//2的元素
    count = {} # dict 也是哈希表
    for num in nums:
        if num in count:
            count[num] += 1
        else:
            count[num] = 1
    n = len(nums)
    for key,value in count.items():
        if value > n//2:
            return key

def main():
    test1 = [1,2,3,3,3,2,4,3,3,3,3]
    print(majorityElement(test1))

if __name__ == "__main__":
    main()