# Given an array A of integers, find the maximum of j - i 
# subjected to the constraint of A[i] <= A[j].
#
# A = [3, 5, 4, 2] ----> 2 because the maximum distance 
# occurs for pair (3, 4).
#



def max_distance_1(arr):

    res = -1
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):

            if arr[j] > arr[i]:
                if j - i > res:
                    res = j - i
    return res


def max_distance_2(arr):

    sorted_arr = []
    for i in range(len(arr)):
        sorted_arr.append([arr[i], i])
    sorted_arr = sorted(sorted_arr, key = lambda x: x[0])

    maxIndex = sorted_arr[-1][1]
    maxDis = -1

    # We need to keep updating maxIndex and the distance 
    # in order to find the max distance because the order matters 
    # like finding max profit in a stock market chart (we cannot substract the higher prices from lower prices that come next)
    for i in range(len(arr)-2, -1, -1):

        if maxIndex - sorted_arr[i][1] > maxDis:
            maxDis = maxIndex - sorted_arr[i][1]
        
        if sorted_arr[i][1] > maxIndex:
            maxIndex = i


arr = [3,5,4,2]
res = max_distance_1(arr)
print(res)

arr = [3,5,4,2]
res = max_distance_1(arr)
print(res)

print(150/12)