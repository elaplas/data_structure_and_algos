

def binary_search(arr, start, end, target):
    """
    Find the index of target 

    Args:
       arr(array), start(int), end(int), target(int): Input array, 
       corresponding start and end indices, the number to search for
    Returns:
       int: target index or -1
    """

    if len(arr) == 1:
        return arr[0]

    mid = (start + end ) // 2

    if arr[mid] == target:
        return mid

    if start >= end:
        return -1

    if target < arr[mid]:
        return binary_search(arr, start, mid, target)
    elif target > arr[mid]:
        return binary_search(arr, mid+1, end, target)

def pivot_search(arr, start, end):
    """
    Find pivot index 

    Args:
       arr(array), start(int), end(int): Input array and corresponding start and 
       end indices
    Returns:
       int: pivot index or -1
    """

    if end < start:
        return -1

    mid = (start + end ) // 2
    if arr[start] > arr[mid]:
        return mid-1
    if arr[end] < arr[mid]:
        return mid

    if arr[start] < arr[mid]:
        return pivot_search(arr, mid + 1, end)
 
    elif arr[mid] < arr[end]:
        return pivot_search(arr, start, mid-1)


def rotated_array_search(input_list, number):
    """
    Find the index by searching in a rotated sorted array

    Args:
       input_list(array), number(int): Input array to search and the target
    Returns:
       int: Index or -1
    """
    
    if not len(input_list):
        return -1
    
    if len(input_list) == 1 and input_list[0] == number:
        return 0

    if len(input_list) == 1 and input_list[0] != number:
        return -1

    pivot_index = pivot_search(input_list, 0, len(input_list)-1)
    res = binary_search(input_list, 0, pivot_index, number)
    if res == -1:
        res = binary_search(input_list, pivot_index+1, len(input_list)-1, number)

    return res



def linear_search(input_list, number):
    for index, element in enumerate(input_list):
        if element == number:
            return index
    return -1
    
def test_function(test_case):
    input_list = test_case[0]
    number = test_case[1]
    if linear_search(input_list, number) == rotated_array_search(input_list, number):
        print("Pass")
    else:
        print("Fail")

test_function([[6, 7, 8, 9, 10, 1, 2, 3, 4], 6])
test_function([[6, 7, 8, 9, 10, 1, 2, 3, 4], 1])
test_function([[6, 7, 8, 1, 2, 3, 4], 8])
test_function([[6, 7, 8, 1, 2, 3, 4], 1])
test_function([[6, 7, 8, 1, 2, 3, 4], 10])
test_function([[6], 6])
test_function([[6], 12])
test_function([[], 12])