def selection_sort(arr,n):
    if n <=1 :
        return arr
    max_idx = find_idx_max(arr,n)
    arr[n-1],arr[max_idx] = arr[max_idx],arr[n-1]
    selection_sort(arr,n-1)

def find_idx_max(arr,n):
    max_idx = 0
    for i in range(1,n):
        if arr[i] > arr[max_idx]:
            max_idx = i
    return max_idx


def main():
    arr = [64, 25, 12, 22, 11]
    n = len(arr)
    selection_sort(arr,n)
    print("Sorted array is:", arr)

if __name__ == "__main__":
    main()