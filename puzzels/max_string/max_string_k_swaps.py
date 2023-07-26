

# Given a string A and integer k, what is maximal lexicographical 
# string that can be made from A if you do B swaps
# input: A = "254", k = 2
# output: "542"


# idea:
# First we calculate all possible swaps b/w two characters which is computed using two for loops
# then we should select k swaps from all possible swaps to find out the max swapped string where 
# the order of the swap matters. This indicates that we need to compute the k-permutations of all 
# possible swaps and then find the one that makes the given string the max possible swapped string
#
#

def max_string(str_x, k):

    possible_swaps = []
    for i in range(len(str_x)):
        for j in range(i+1, len(str_x)):
            possible_swaps.append([i,j])
    
    # For simplicity we work with the indices of "possible_swaps" 
    possible_k_swaps = []
    if k == 1:
        possible_k_swaps = [i for i in range(len(possible_swaps))]
    else:
        possible_k_swaps = gen_k_permutations([i for i in range(len(possible_swaps))], k)

    # Find max swapped string
    max_swapped_str = str_x
    for swaps in possible_k_swaps:
        swapped_str = list(str_x)
        for swap in swaps:
            tmp = swapped_str[possible_swaps[swap][0]]
            swapped_str[possible_swaps[swap][0]] = swapped_str[possible_swaps[swap][1]] 
            swapped_str[possible_swaps[swap][1]] = tmp

        swapped_str = "".join(swapped_str)
        if swapped_str > max_swapped_str:
            max_swapped_str = swapped_str
    
    return max_swapped_str


def gen_k_permutations(arr, k):

    if k == 1:
        return [[arr[i]] for i in range(len(arr))] 
    
    permutations = gen_k_permutations(arr, k-1)

    new_permutations = []
    for permutation in permutations:
        for i in range(len(arr)):
            if arr[i] not in permutation:
                copy_permutation = [el for el in permutation]
                copy_permutation.append(arr[i])
                new_permutations.append(copy_permutation)

    return new_permutations


str_x = "254"
res = max_string(str_x, 2)
print(res)
    