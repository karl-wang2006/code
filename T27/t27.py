def removeElement(nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        # 列表=新列表不会改变main里的，要nums[:]遍历才会修改
        # 学会写列表表达式
        nums[:] = [x for x in nums if x != val ]
        return len(nums)

def removeElement2(nums, val):
    """
    :type nums: List[int]
    :type val: int
    :rtype: int
    """
    # 双指针法是这道题的考点
    length = len(nums)
    left = 0
    right = length - 1
    while left <= right:
        if nums[left] == val:
            nums[left], nums[right] = nums[right], nums[left]
            right -= 1
            # left += 1 错误！换完还有可能是一样的！
        else:
            left += 1
    # if left == right and nums[left] != val: # 边界情况，检查指针相等，这里判断边界没问题就合并
    #     return left + 1
    else:
        return left
                      

def main():
    test1 = [3,2,2,3]
    val1 = 3
    print(removeElement2(test1,val1))
    print(test1)
    test2 = [0,1,2,2,3,0,4,2]
    val2 = 2
    print(removeElement2(test2,val2))
    print(test2)

if __name__ == "__main__":
      main()