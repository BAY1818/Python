
def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (right + left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

arr = [2, 4, 7, 10, 15, 20, 25, 30, 35, 40]

target = 30

result = binary_search(arr, target)
print("Found at Index: ", result)