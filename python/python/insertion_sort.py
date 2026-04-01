def insertion_sort(arr,n):
    if n == 1:
        return arr
    insertion_sort(arr,n-1)
    key = arr[n-1]
    i = n - 1
    while i > 0 and arr[i-1] > key:
        arr[i] = arr[i - 1]
        i -= 1
    arr[i] = key
    return arr

def main():
    arr = [12, 11, 13, 5, 6]
    n = len(arr)
    print(insertion_sort(arr,n))
if __name__ == "__main__":
    main()