def findMedianSortedArrays1(nums1, nums2): #双指针法，O(n)
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1 = len(nums1)
        len2 = len(nums2)
        p1 = 0
        p2 = 0
        ret = []
        while p1 < len1 and p2 < len2:
            if nums1[p1] < nums2[p2]:
                ret.append(nums1[p1])
                p1 += 1
            else:
                ret.append(nums2[p2])
                p2 += 1
        if p1 == len1:
            for i in range(p2,len2):
                ret.append(nums2[i])
        if p2 == len2:
            for j in range(p1,len1):
                ret.append(nums1[j])
        tot = len1 + len2
        if tot % 2 == 0:
            return (ret[tot//2-1] + ret[tot//2])/2
        else:
            return ret[(tot-1)//2]
        
def findMedianSortedArrays2(nums1,nums2): #分治法，O(log(m+n))
    len1 = len(nums1)
    len2 = len(nums2)
    L = len1 + len2
    if L % 2 == 0:
        return (find_kth(nums1,nums2,L//2) + find_kth(nums1,nums2,L//2+1))/2.0
    else:
        return find_kth(nums1,nums2,L//2+1)
    
def find_kth(arr1,arr2,k): #找到两个数组里第k小的数并返回
    if not arr1: return arr2[k-1] # arr1 为空数组,返回arr2里的第k小
    if not arr2: return arr1[k-1] # 同理
    if k <= 1: # 最小情况
        return min(arr1[0],arr2[0]) #顺序不能换，因为要先判断数组是否为空
    len1 = len(arr1)
    len2 = len(arr2)
    i = min(len1,k//2) # 从arr1中取k的一半出来,不够就取全部的出来
    j = min(len2,k//2)
    if arr1[i - 1] > arr2[j - 1]: # arr2的这一半比arr1的这部分最大值都要小，则第k小的数不可能在arr2的这一部分里
        return find_kth(arr1,arr2[j:],k-j) #问题范围缩小
    else:
        return find_kth(arr1[i:],arr2,k-i)



def main():
    test1 = [1,2,3]
    test2 = [-1,0,4,6]
    print(findMedianSortedArrays2(test1,test2))

if __name__ == "__main__":
    main()