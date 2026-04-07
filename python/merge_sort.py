def merge_sort(arr,low=0,high=None): # 传入整个数组和要排序的始末下标
    if high is None:
        high = len(arr) - 1 
    if  low == high:
        return 0 , [arr[low]] # 不是返回arr，arr本身没有改变，改变的是始末下标，所以要返回单个元素的数组
    mid = (low + high)//2
    left_inv , arr1 = merge_sort(arr,low,mid)
    right_inv , arr2 = merge_sort(arr,mid + 1,high)
    cross_inv, ret = merge_arr(arr1,arr2)
    total = left_inv + right_inv + cross_inv
    return total , ret

def merge_arr(arr1,arr2):
    p1 = 0
    p2 = 0
    len1 = len(arr1)
    len2 = len(arr2)
    ret = []
    total = 0
    while p1 < len1 and p2 < len2:
        if arr1[p1] <= arr2[p2]:
            ret.append(arr1[p1])
            p1 += 1
            total += p2
        else:
            ret.append(arr2[p2])
            p2 += 1
    if p1 == len1:
        for i in range(p2,len2):
            ret.append(arr2[i])
    if p2 == len2:
        for j in range(p1,len1):
            ret.append(arr1[j])
            total += p2
    return total , ret

def main():
    test1 = [3,2,6,1,-1,0]
    total,ret = merge_sort(test1)
    print(total)
    print(ret)

if __name__ == "__main__":
    main()