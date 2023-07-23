

def first_missing_int(arr):

    sorted_arr = sorted(arr)
    res = 1

    for el in sorted_arr:
        if el == res:
            res += 1
            
    return res
        


A = [1, 3, 2, 4]
res = first_missing_int(A)
print(res)


A = [1,2,0]
res = first_missing_int(A)
print(res)

A = [3,4,-1,1]
res = first_missing_int(A)
print(res)

A = [-8,-7,-6]
res = first_missing_int(A)
print(res)
