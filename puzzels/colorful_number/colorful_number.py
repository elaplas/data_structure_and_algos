
"""Problem:
For Given Number A, find if it's a COLORFUL number or not.

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different

Return 1 if A is a COLORFUL number, else return 0

Example Explanation
A = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since the product of every digit of a sub-sequence is different.

Output: 1

"""


"""The idea is to recursively generate the contiguous combinations (sub-sequences) at each step
    and check if the product of a new combination is already seen then return "False" otherwise continue
"""


def is_colorful_num(number):
    map = {}
    combinations = []
    return is_colorful_num_helper(number, map, combinations)

def is_colorful_num_helper(number, map, combinations):

    if number == 0:
        combinations.append(0)
        return True
    
    res = is_colorful_num_helper(number//10, map, combinations)

    if not res:
        return False

    new_combinations = []
    # Append "0" for adding the reminder itself in to the combinations list for the next function call
    new_combinations.append(0)
    reminder = number % 10

    for num in combinations:
        new_combination = (num*10) + reminder

        cur_num = new_combination
        product = 1
        while cur_num:
            product *= (cur_num%10)
            cur_num = cur_num //10
        
        if product in map:
            return False
        else:
            map[product] = 1 

        new_combinations.append(new_combination)

    # Copy new combinations in order not to overwrite the reference list "combinations" by simply using the "equal sign"
    combinations.clear()
    for el in new_combinations:
        combinations.append(el)
    
    return True

num = 3245 
res = is_colorful_num(num)
print(res)


num = 326
res = is_colorful_num(num)
print(res)

num = 1
res = is_colorful_num(num)
print(res)

num = 23
res = is_colorful_num(num)
print(res)