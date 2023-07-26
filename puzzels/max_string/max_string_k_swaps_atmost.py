
# Given a string A and integer k, what is maximal lexicographical 
# string that can be made from A if you do atmost B swaps
# input: A = "254", k = 2
# output: "542"


# idea:
# First we calculate all possible swaps which are computed using two for loops;
# then, we try each swap recursively till we found the max swapped string. 
# The recursion is done k times (depth of recursion)  


def max_string(in_str, k):
    res = [in_str]
    max_string_helper(in_str, k, res)
    return res[0]

def swap_str(in_str, i, j):

    copy_str = list(in_str)
    tmp = copy_str[i]
    copy_str[i] = copy_str[j]
    copy_str[j] = tmp

    return "".join(copy_str) 

def max_string_helper(in_str, k, max_swapped_str):

    if k == 0:
        return 
    
    for i in range(len(in_str)):
        for j in range(i+1, len(in_str)):

            swapped_str = swap_str(in_str, i, j)

            if swapped_str > max_swapped_str[0]:
                max_swapped_str[0] = swapped_str

            max_string_helper(swapped_str, k-1, max_swapped_str)


str_x = "254"
res = max_string(str_x, 2)
print(res)
    


