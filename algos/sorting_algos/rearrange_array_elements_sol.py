

def merge_sort(arr, start, end):
    """
    Sort a list 

    Args:
       input_list, starting index, ending index
    Returns:
       (list): sorted list 
    """
    
    if start >= end:
        return [arr[end]]

    mid = (start + end) // 2

    left = merge_sort(arr, start, mid)
    right = merge_sort(arr, mid+1, end)

    ptr_left = 0
    ptr_right = 0
    merged = []
    while ptr_left < len(left) and ptr_right < len(right):
        if left[ptr_left] < right[ptr_right]:
            merged.append(left[ptr_left])
            ptr_left += 1
        else:
            merged.append(right[ptr_right])
            ptr_right +=1
    
    merged += left[ptr_left:]
    merged += right[ptr_right:]

    return merged


def rearrange_digits(input_list):
    """
    Rearrange Array Elements so as to form two number such that their sum is maximum.

    Args:
       input_list(list): Input List
    Returns:
       (int),(int): Two maximum sums
    """
    if not len(input_list):
        return 0,0

    if len(input_list) == 1:
        return input_list[0],0

    sorted_list = merge_sort(input_list, 0, len(input_list)-1)
    first_number = sorted_list[-1]
    second_number = sorted_list[-2]

    for i in range(len(sorted_list)-3 , -2, -2):
        
        if i >= 0:
            first_number *= 10
            first_number += sorted_list[i]
        if i-1 >=0:
            second_number *= 10
            second_number += sorted_list[i-1]

    return first_number, second_number

def test_function(test_case):
    output = rearrange_digits(test_case[0])
    solution = test_case[1]
    if sum(output) == sum(solution):
        print("Pass")
    else:
        print("Fail")

test_function([[1, 2, 3, 4, 5], [542, 31]])
test_function([[4, 6, 2, 5, 9, 8], [964, 852]])
test_function([[], [0, 0]])
test_function([[12], [12, 0]])