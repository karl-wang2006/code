def FindMaxSum(arr,n): # 输入一个数组和长度，输出连续子数组的最大和
    if n <= 1:
        return arr[0]
    mid = n//2
    return max(FindMaxSum(arr[:mid],mid),CrossMiddleSum(arr,mid),FindMaxSum(arr[mid:],n-mid))

def CrossMiddleSum(arr,mid): # 输入一个数组和中间数下标mid，输出包含下标为mid元素的连续子数组最大和 
    L = len(arr)
    ret = arr[mid]
    sum = arr[mid]
    for i in range(mid-1,-1,-1):
        sum += arr[i]
        if sum > ret:
            ret = sum
    sum = ret
    for j in arr[mid+1:]:
        sum += j
        if sum > ret:
            ret = sum
    return ret
        
def main():
    test1 = [-2,1,-3,4,-1,2,1,-5,4] # 输出为连续子数组 [4,-1,2,1] 的和最大，为 6 
    test2 = [1] # 1
    test3 = [5,4,-1,7,8] # 23
    print(FindMaxSum(test3,len(test3)))

if __name__ == "__main__":
    main()

