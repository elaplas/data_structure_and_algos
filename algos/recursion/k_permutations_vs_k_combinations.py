
# all combinations with length k
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
        return [[el] for el in range(len(arr))]
    
    permutations = k_permutations(arr, k-1)
    new_permutations = []
    for permutation in permutations:
        for num in arr:
            if num not in permutation:
                copy = [el for el in permutation]
                copy.append(num)
                new_permutations.append(copy)

    return new_permutations


arr = [1,2,3,4,5]
res = k_permutations(arr, 3)
print(res)

print("...................................")

arr = [1,2,3,4,5]
res = k_combinations(arr, 3)
print(res)