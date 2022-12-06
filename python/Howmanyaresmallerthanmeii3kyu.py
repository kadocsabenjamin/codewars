import bisect

def smaller(arr):
    sorted_arr = sorted(arr)
    result = []
    
    for x in arr:
        i = bisect.bisect_left(sorted_arr, x)
        result.append(i)
        del sorted_arr[i]
    
    return result

    


print(smaller([5, 4, 3, 2, 1]))