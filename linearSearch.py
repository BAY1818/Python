
def linearSearch(arr, target):
    

    for i in range (len(arr) - 1):
        if arr[i] == target:
            return i
    return -1


arr = [2, 4, 7, 10, 15, 20, 25, 30, 35, 40]
target = 20

rslt = linearSearch(arr, target)
print("Found at index ", rslt)