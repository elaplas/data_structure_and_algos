

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
    if n==1:
        return "11"
    return count_and_say_helper(n, 1, "11")


def count_and_say_helper(n, call_counter, num):

    if call_counter == n:
        return num
    
    new_num = ""
    counter = 1
    for i in range(len(num)-1):
        if num[i] == num[i+1]:
            counter += 1
        else:
            new_num += str(counter)
            new_num += num[i]
            counter = 1
    
    new_num += str(counter)
    new_num += num[-1]

    return count_and_say_helper(n, call_counter+1, new_num)




res = count_and_say(1)
print(res)


res = count_and_say(2)
print(res)


res = count_and_say(3)
print(res)