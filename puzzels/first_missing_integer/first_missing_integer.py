

def first_missing_int(arr):

    sorted_arr = sorted(arr)
    missing_int = None
    min_found_positive_num = None
    max_found_positive_num = None

    for i in range(len(arr)-1):

        if sorted_arr[i] < 0:
            continue

        if sorted_arr[i+1] < 0:
            continue
        
        if sorted_arr[i+1] - sorted_arr[i] > 1:
            missing_int = sorted_arr[i]+1
            break

    for i in range(len(arr)):
         
         if sorted_arr[i] > 0:
            if not min_found_positive_num:
                min_found_positive_num = max_found_positive_num = sorted_arr[i]
            else:
                max_found_positive_num = sorted_arr[i]
    
    if missing_int:
        return missing_int
    else:
        if min_found_positive_num:
            if min_found_positive_num == 1:
                return max_found_positive_num + 1
            else:
                min_found_positive_num + 1
        else:
            return 1

        
        
    

A = [1,2,0]
res = first_missing_int(A)
print(res)

A = [3,4,-1,1]
res = first_missing_int(A)
print(res)

A = [-8,-7,-6]
res = first_missing_int(A)
print(res)
