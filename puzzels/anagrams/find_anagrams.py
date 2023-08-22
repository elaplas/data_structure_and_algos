


"""Find anagrams in a list of string
*
* input: cat, dog, god, tca
* output: [[0, 3], [1,2]]
*
* Hint: Anagram: a word formed by rearranging the letters of another
*
*
"""

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
