

def binary_search(arr, s, e, target):
    """
    Find the index of target 

    Args:
       arr(array), start(int), end(int), target(int): Input array, 
       corresponding start and end indices, the number to search for
    Returns:
       int: target index or -1
    """

    if s > e:
        return -1

    mid = (s+e)//2

    if target < arr[mid]:
        e = mid-1
    elif target > arr[mid]:
        s = mid+1
    else:
        return mid # the target is found

    return binary_search(arr, s, e, target)

def pivot_search(arr, start, end):
    """
    Find pivot index 

    Args:
       arr(array), start(int), end(int): Input array and corresponding start and 
       end indices
    Returns:
       int: pivot index or -1
    """

    # Base case is when the size of search space is 2 e.g. sub-array [8, 1] in [6, 7, 8, 1, 2, 3, 4]
    if end - start == 1:
        return (start+end)//2

    mid = (start + end)//2

    if arr[mid] < arr[start]: 
        end = mid     # Set end to mid index and not mid-1 because we want to keep the pivot point till we return it 
    elif arr[mid] > arr[end]:
        start = mid  # Set end to mid index and not mid+1 because we want to keep the pivot point till we return it 
    else:
        return -1  # there is no pivot (an index where a rotation happens)

    return pivot_search(arr, start, end)


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