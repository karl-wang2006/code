#原地翻转arr的前n个元素，返回翻转后的数组
def reverse_arr(arr,n):
    if n <= 1: #一个元素不用翻转
        return arr
    key = arr[n-1]
    i = n - 2
    while i >= 0 :
        arr[i+1] = arr[i]
        i -= 1
    arr[0] = key
    return arr       