
def sqrt(number):
    """
    Calculate the floored square root of a number

    Args:
       number(int): Number to find the floored squared root
    Returns:
       int: Floored Square Root
    """

    if number == 0:
        return 0

    sqrt_root = 1
    while (sqrt_root*2) * (sqrt_root*2) <= number:
        sqrt_root *= 2

    while (sqrt_root+1) * (sqrt_root+1) <= number:
        sqrt_root += 1

    return sqrt_root

print("...............sqrt faster..............")
print ("Pass" if  (3 == sqrt(9)) else "Fail")
print ("Pass" if  (0 == sqrt(0)) else "Fail")
print ("Pass" if  (4 == sqrt(16)) else "Fail")
print ("Pass" if  (1 == sqrt(1)) else "Fail")
print ("Pass" if  (5 == sqrt(27)) else "Fail")
print ("Pass" if  (1643167 == sqrt(2700000000000)) else "Fail")