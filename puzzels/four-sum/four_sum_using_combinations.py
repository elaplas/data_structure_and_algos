

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





# generates all combinations with length k
def k_combinations(arr, k):
    result = []
    gen_combinations(arr, 0, k, result)
    return result

# helper function for generating all combinations with length k
def gen_combinations(arr, i, k, result):

    if i == len(arr):
        return [[]]

    combinations = gen_combinations(arr, i+1, k, result)
    ith_element = arr[i]
    new_combinations = []
    for combination in combinations:
        copy_1 = [el for el in combination]
        copy_2 = [el for el in combination]
        copy_2.insert(0, ith_element)
        new_combinations.append(copy_1)
        if len(copy_2) <= k:
            new_combinations.append(copy_2)
    
        if len(copy_2) == k:
            result.append(copy_2)

    return new_combinations

# Solve four-sum problem by generating combinations - O(2^n) -> exponential
def four_sum(arr, target):
    combinations = k_combinations(arr, 4)
    res = []
    for combination in combinations:
        if sum(combination) == target:
            res.append(combination)
    return res

arr = [1, 0, -1, 0, -2, 2]
target = 0
res = four_sum(arr, target)
print(res)