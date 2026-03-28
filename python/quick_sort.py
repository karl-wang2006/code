import random
# def quick_sort(arr,n):
#     if n <= 1:
#         return arr
#     pivot = arr[n//2]
#     left = [x for x in arr if x < pivot]
#     middle = [x for x in arr if x == pivot]
#     right = [x for x in arr if x > pivot]
#     return quick_sort(left, len(left)) + middle + quick_sort(right, len(right))
def my_quick_sort(arr, n):
    if n <= 1:
        return arr
    pivot = random.choice(arr)
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return my_quick_sort(left, len(left)) + middle + my_quick_sort(right, len(right))


def main():
    arr = [3,6,8,10,1,2,1]
    sorted_arr = my_quick_sort(arr, len(arr))
    print(sorted_arr)

if __name__ == "__main__":
    main()