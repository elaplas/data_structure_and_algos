

#Given an unsorted array arr[0..n-1] of size n, find the minimum 
#length subarray arr[s..e] such that sorting this subarray makes 
#the whole array sorted. 
#Examples: 
#
#If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], 
#your program should be able to find that the subarray lies between 
#indexes 3 and 8. If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], 
#your program should be able to find that the subarray lies between indexes 2 and 5.



def min_unsorted_subarray_1(arr):

    sorted_arr = sorted(arr)
    s = e = -1
    for i in range(len(arr)):

        if arr[i] != sorted_arr[i]:
            if s == -1:
                s = i
                e = i+1
            else:
                e += 1

    # There is no unsorted array
    if s == -1:
        return [-1, -1]
    else:
        return [s, e]


def min_unsorted_subarray_2(arr):
    s = e = -1

    # Find the index of an unsorted element from left
    for i in range(len(arr)-1):
        if arr[i+1] < arr[i]:
            s = i
            break

    # Find the index of an unsorted element from right
    for i in range (len(arr)-1, 0, -1):
        if arr[i] < arr[i-1] :
            e = i+1
            break
    
    # 1- None of elements from 0-s shouldn't be bigger than arr[s] element
    # 2- None of elements from e-arr[-1] shouldn't be smaller than arr[e] element
    # if 1 or 2 is the case we should move the s or e to the left or to the right
    min_unsorted_el = max_unsorted_el = None
    if s != -1 and e != -1:        
        min_unsorted_el = arr[s]
        max_unsorted_el = arr[e]

        for i in range(s, e+1):
            if arr[i] < min_unsorted_el:
                min_unsorted_el = arr[i]
            
            if arr[i] > max_unsorted_el:
                max_unsorted_el = arr[i]

        for i in range(0, s):
            if arr[i] > min_unsorted_el :
                s = i
                break
        for i in range(len(arr)-1, -1, e):
            if arr[i] < max_unsorted_el:
                e = i
                break

    if s == -1:
        return [-1, -1]
    else:
        return[s, e]


arr = [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60]
res = min_unsorted_subarray_1(arr)
print(res)

arr = [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60]
res = min_unsorted_subarray_2(arr)
print(res)