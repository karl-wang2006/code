# 在arr的前n个元素里查找target，返回T/F
def find_target(arr,n,target): 
    if n <= 0: #没有元素匹配
        return False
    # 在前n-1个里查找到了或第n个查找到了
    if find_target(arr,n-1,target) or target == arr[n-1]:
        return True
    else:
        return False
    
def main():
    arr =[3,6,7,2,7,3]
    n = len(arr)
    target = 4 
    if find_target(arr,n,target):
        print("Found")
    else:
        print("Not found")

if __name__ == "__main__":
    main()