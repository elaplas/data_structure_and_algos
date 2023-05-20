
'''
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

    Note:

        Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
        The solution set must not contain duplicate quadruplets.

Example : 

Given array S = {1 0 -1 0 -2 2}, and target = 0

A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
'''


def k_permutations(arr, k):
    
    if k == 1:
        return [[i] for i in range(len(arr))]
    
    permutations = k_permutations(arr, k-1)
    new_permutations = []
    for permutation in permutations:
        for index in range(len(arr)):
            if index not in permutation:
                copy = [el for el in permutation]
                copy.append(index)
                new_permutations.append(copy)

    return new_permutations


def is_in_res(arr, arr_list):

    for c_arr in arr_list:
        lookup = set(c_arr)
        for el in arr:
            if el in lookup:
                lookup.remove(el)
            else:
                break
        
        if len(lookup) == 0:
            return True

    return False


def four_sum(arr, target):

    permutations = k_permutations(arr, 4)
    result = []
    for permutation in permutations:
        if sum([arr[el] for el in permutation ]) == target and sorted([arr[el] for el in permutation]) not in result:
            result.append(sorted([arr[el] for el in permutation ]))
    
    return result



arr = [1, 0, -1, 0, -2, 2]
target = 0
res = four_sum(arr, target)
print(res)

