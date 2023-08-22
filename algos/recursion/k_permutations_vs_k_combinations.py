
# all combinations with length k - O(n!/(k!(n-k)!)
def k_combinations(arr, k):
    result = []
    gen_combinations(arr, 0, k, result)
    return result

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

# all permutations with length k - O(n!/(n-k)!)
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


arr = [1,2,3,4]
permutations = k_permutations(arr, 2)
result = []
for permutation in permutations:
    result.append([arr[index] for index in permutation])
print(result)