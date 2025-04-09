

def combine(A, i):

    if i == -1:
        return [[]]
    
    res = combine(A, i-1)
    new_res = []
    for comb in res:
        copy_comb = [el for el in comb]
        copy_comb.append(A[i])
        new_res.append(copy_comb)
    
    return new_res + res


def permute(A, i):

    if i == -1:
        return [[]]
    
    res = permute(A, i-1)
    new_res = []
    for per in res:
        for j in range(len(per)+1):
            copy_per = [p for p in per]
            copy_per.insert(j, A[i])
            new_res.append(copy_per)
    
    return new_res + res




B = [1,2,3]
print(combine(B, 2))
print("----------------------------------------------------------------")
print(permute(B, 2))

