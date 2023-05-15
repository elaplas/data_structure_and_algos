


"""Find anagrams in a list of string
*
* input: cat, dog, god, tca
* output: [[0, 3], [1,2]]
*
* Hint: Anagram: a word formed by rearranging the letters of another
*
*
"""


# Time complexity: O(n^3logn), space complexity: O(1)
def find_anagrams(list_str):
    result = []
    for i in range(len(list_str)):
        for j in range(i+1, len(list_str)):
            if is_anagram(list_str[i], list_str[j]):
                result.append([i, j])
    return result

def is_anagram(str1, str2):
    short = str1
    long = str2
    if len(str2) < len(str1):
        short = str2
        long = str1
    
    short = sorted(short)
    long = sorted(long)

    ptr_short = 0
    ptr_long = 0
    while ptr_short < len(short) and ptr_long < len(long):
        if short[ptr_short] == long[ptr_long]:
            ptr_short += 1
            ptr_long += 1
        else:
            ptr_long +=1
    
    if ptr_short == len(short):
        return True
    else:
        return False

# Time complexity: O(n^2logn) space complexity: O(n)
def find_anagrams_optimized(list_str):
    map = {}
    result = []
    for i in range(len(list_str)):
        word = sorted(list_str[i])
        word = ''.join(word)
        if word in map:
            map[word].append(i)
        else:
            map[word] = [i]
    for key in map:
        result.append(map[key])
    return result



list_str = ["cat", "dog", "god", "tca"]
res = find_anagrams(list_str)
print(res)


list_str = ["cat", "dog", "god", "tca"]
res = find_anagrams_optimized(list_str)
print(res)
