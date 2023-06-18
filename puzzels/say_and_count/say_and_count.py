

"""
input: 1
output: 11

input: 2
output: 21

input: 3
output: 1211

seq: 11, 12, 1211, ...

"""




def count_and_say(n):
    return count_and_say_helper(n, 0, 1)


def count_and_say_helper(n, call_counter, num):

    if call_counter == n:
        return num
    
    stack = []

    while num:
        cur_dig = num %10 
        num = num//10
        stack.append(cur_dig)
    
    counter = -1
    dig = -1
    new_num = 0
    while len(stack):

        cur_dig = stack.pop()

        if dig == -1:
            dig = cur_dig
            counter = 1
        
        else:
            if cur_dig == dig:
                counter += 1
            else:
                new_num *= 10
                new_num += counter
                new_num *= 10
                new_num += dig

                dig = cur_dig
                counter = 1
    
    new_num *= 10
    new_num += counter
    new_num *= 10
    new_num += dig

    return count_and_say_helper(n, call_counter+1, new_num)




res = count_and_say(1)
print(res)


res = count_and_say(3)
print(res)