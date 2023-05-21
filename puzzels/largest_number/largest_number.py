import functools


"""Given a list of non-negative integers, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.

input: A = [3, 30, 34, 5, 9]
output: 9534330

"""


# We need to first figure out if xy > yx given x and y: For example if x = 5, y = 32
# then we need to first form 532 and 325 and compare them with each other.  
def compare(x, y):
    
    num_dig_x = get_num_dig(x)
    num_dig_y = get_num_dig(y)
    fit_x = x * (10**num_dig_y)
    fit_y = y * (10**num_dig_x)

    if fit_x + y > fit_y + x:
        return -1
    else:
        return 1

def get_num_dig(x):
    cur_num = x
    counter = 0
    while cur_num:
        cur_num //= 10
        counter += 1 
    return counter


def get_largest_num(arr):
    sorted_arr = sorted(arr, key = functools.cmp_to_key(compare))
    res = ""
    for el in sorted_arr:
        res += str(el)
    
    return res

arr = [3, 5, 34, 30, 9]
res = get_largest_num(arr)
print(res)