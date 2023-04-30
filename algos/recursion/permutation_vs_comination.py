

# Order rearrangement of members -> O(n) = n!
def gen_permutations(arr):
    return gen_permutation_rec(arr,0)

def gen_permutation_rec(arr, i):

    if i >= len(arr):
        return [[]]

    
    cur_permutations = gen_permutation_rec(arr, i+1)

    ith_el = arr[i]
    new_permutations = []
    for permutation in cur_permutations:
        for i in range(len(permutation)+1):
            copy_permutation = [el for el in permutation]
            copy_permutation.insert(i, ith_el)
            new_permutations.append(copy_permutation)

    return new_permutations


# member selection -> O(2^n)
def gen_combinations(arr):
    return gen_combinations_rec(arr, 0)


def gen_combinations_rec(arr, i):

    if i >= len(arr):
        return [[]]

    cur_combination = gen_combinations_rec(arr, i+1)

    ith_el = arr[i]
    new_combinations = []
    for combination in cur_combination:
        copy_combination = [el for el in combination]
        new_combinations.append(combination)
        copy_combination.insert(0, ith_el)
        new_combinations.append(copy_combination)
        
    return new_combinations




arr = [1,2,3]

res = gen_permutations(arr)
print(res)
print(len(res))
print("----------------------------------------------------------------")
res = gen_combinations(arr)
print(res)
print(len(res))

