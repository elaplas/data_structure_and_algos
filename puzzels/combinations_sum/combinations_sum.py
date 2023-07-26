

# Given an array of candidate numbers A and a target number B,
# find all unique combinations in A where the candidate numbers sums to B.
# 
# input:   A = [2, 3, 6, 7], sum = 7
# output:  [ [2, 2, 3] , [7] ]
# 











def combinations_sum(arr, num):
    return combinations_sum_helper(arr, -1, num)


def combinations_sum_helper(arr, j, num):

    if num == 0:
        return [[arr[j]]]
    
    res_t_1 = []
    for i in range(len(arr)):
        if (num - arr[i] >= 0):
            res_t = combinations_sum_helper(arr, i, num-arr[i])
            for comb in res_t:
                new_comb = comb
                # "j = -1" is only for handeling the first call back 
                if j != -1:
                    new_comb.append(arr[j])
                res_t_1.append(new_comb)
    return res_t_1


arr = [1,2,3]
res = combinations_sum(arr, 6)
print(res)




def combinations_sum_with_mem(arr, num):
    MEM = {}
    return combinations_sum_with_mem_helper(arr, -1, MEM, num)


def combinations_sum_with_mem_helper(arr, j, mem, num):

    if num in mem:
        return mem[num]

    if num == 0:
        return [[arr[j]]]
    
    res_t_1 = []
    for i in range(len(arr)):
        if (num - arr[i] >= 0):
            res_t = combinations_sum_helper(arr, i, num-arr[i])
            for comb in res_t:
                new_comb = comb
                # "j = -1" is only for handeling the first call back 
                if j != -1:
                    new_comb.append(arr[j])
                res_t_1.append(new_comb)

    mem[num] = res_t_1

    return res_t_1

print(".............with mem...........")
arr = [1,2,3]
res = combinations_sum_with_mem(arr, 6)
print(res)