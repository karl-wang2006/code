def re_max(arr,n): #返回前n个元素里的最大数
    if n <= 1: #只有一个时返回那一个
        return arr[0]
    tmp = re_max(arr,n-1)
    if tmp > arr[n-1]:
        return tmp
    else:
        return arr[n-1]

def main():
    arr = [2,3]
    n = len(arr)
    print(re_max(arr,n))

if __name__ == "__main__":
    main()
    