def bubble_sort(arr,n): #本身这个函数代表的就是对前n个元素进行排序
    # 一定要设置递归的终点，否则就会死循环
    # 当n=1时，说明前面只有一个元素了，这个时候就不需要排序了，直接返回就好了
    if n<= 1:
        return arr
    # 先冒泡排好最后一个元素
    for i in range(n-1):
        if arr[i] > arr[i+1]:
            arr[i],arr[i+1] = arr[i+1],arr[i]
    # 再按照同样的方法排好前面n-1个元素
    bubble_sort(arr,n-1)
    return arr

# 现在尝试用另一种递归思路，先把后n-1个元素排好，然后把第一个元素插入到正确的位置上
def bubble_sort_2(arr,n):
    # 同样设置递归的终点
    if n <= 1:
        return arr
    # 先把后面n-1个元素排好
    bubble_sort_2(arr,n-1)
    # 再把第一个元素插入到正确的位置上
    key = arr[0]
    i = 0
    while i < n-1 and arr[i+1] < key:
        arr[i] = arr[i+1]
        i += 1
    # 跳出循环后，i指向的就是第一个元素应该插入的位置
    arr[i] = key
    return arr


def main():
    arr = [64, 34, 25, 12, 22, 11, 90]
    n = len(arr)
    print("Sorted array is:", bubble_sort(arr,n))

if __name__ == "__main__":
    main()