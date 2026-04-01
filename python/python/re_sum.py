def re_sum(n): #就表示前面n个数的和，不要在乎怎么做到的
    if n <= 1:
        return n
    re_sum(n-1) # 就表示前面n-1个数的和，不要在乎怎么做到的
    return re_sum(n-1) + n # 就表示前面n-1个数的和加上n，就是前面n个数的和了

def main():
    n = 5
    print(re_sum(n))
if __name__ == "__main__":
    main()