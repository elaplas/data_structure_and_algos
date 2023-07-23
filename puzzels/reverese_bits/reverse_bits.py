

# Reverse the bits of an 32 bit unsigned integer A:
# 0 ----bits---> 00000000000000000000000000000000  ---reversed---> 00000000000000000000000000000000 --> 0
# 13----bits ---> 00000000000000000000000000001101  ---reversed---> 10110000000000000000000000000000 --> 4026531840



def reverse_bits(num):

    bits = []
    
    while num:
        bit = num % 2
        bits.append(bit)
        num = num//2

    reversed_num = 0
    for i in range(len(bits)):

        reversed_num += (bit* (2**(31-i)))
    
    return reversed_num


num = 13
revered_num = reverse_bits(num)
print(revered_num)