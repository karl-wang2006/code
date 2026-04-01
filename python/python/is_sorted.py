def is_sorted(arr,n): #输出T/F,判断前n个元素是否按照升序排列
    if n <= 1:
        return True #只有一个元素必然满足条件
    if is_sorted(arr,n-1) and arr[n-1] >= arr[n-2]: #在前n-1个已经满足升序条件下且最后一个元素比倒数第二个大
        return True
    else:
        return False
         
def main():
    arr = [1,8,8,9]
    n = len(arr)
    if is_sorted(arr,n):
        print("升序")
    else:
        print("非升序")
if __name__ == "__main__":
    main()