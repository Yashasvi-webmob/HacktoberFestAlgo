def replaceElements(arr):
    new_arr = arr.copy()
    if len(arr) == 1:
        arr[0] = -1
        return arr
    else:
        for i in range(len(arr)-1):
            arr[i] = max(new_arr[i+1:])
        arr[-1] = -1
    return arr

arr = [17,18,5,4,6,1]
print(replaceElements(arr))