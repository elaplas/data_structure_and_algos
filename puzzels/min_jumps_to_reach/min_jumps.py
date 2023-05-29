

def min_jumps(arr):

    res = []
    for i in range(len(arr)-1):
        res_x = min_jumps_helper(arr, i)
        if res_x != -1:
            res.append(res_x + i)
    
    if len(res):
        return min(res)
    else:
        return -1

    
def min_jumps_helper(arr, i):

    cur_index = i
    min_num_jumps = 0

    while cur_index < len(arr)-1:
        
        min_num_jumps += 1
        cur_index += arr[cur_index]
    
    if cur_index == len(arr)-1:
        return min_num_jumps
    else:
        return -1
    

def min_jumps1(arr):
    
    res = []
    for i in range(len(arr)):
        res_x = min_jumps1_helper(arr, i)
        if res_x != -1:
            res.append(res_x+i)
    
    if len(res):
        return min(res)
    else:
        return -1
        

def min_jumps1_helper(arr, i):
    if i == len(arr)-1:
        return 0
    
    if i > len(arr)-1:
        return -1

    return 1 + min_jumps1_helper(arr, i + arr[i])

    

arr = [2,1,1]
res = min_jumps(arr)
print(res)

arr = [2,3,1,1,4]
res = min_jumps(arr)
print(res)

arr = [2,1,1]
res = min_jumps1(arr)
print(res)

arr = [2,3,1,1,4]
res = min_jumps1(arr)
print(res)
