def wildcard_matcher(pattern, text):

    rows = len(text) + 1
    cols = len(pattern) + 1

    MEM = [[False for _ in range(cols)] for _ in range(rows)]

    #MEM = np.zeros((rows, cols))

    # For the cae the last two characters are the same
    MEM[-1][-1] = True

    # For the case the fist character of pattern is '*'
    # and its successor character is not the same as the one of the test
    MEM[-1][0] = True

    for i in range(rows-2, -1, -1):
        for j in range(cols-2, -1, -1):

            if text[i] == pattern[j]:
                MEM[i][j] = MEM[i+1][j+1]
            elif j == len(pattern)-1 and pattern[j] == '*':
                MEM[i][j] = True
            elif j != len(pattern)-1 and pattern[j] == '*' :

                if pattern[j+1] == text[i]:
                    MEM[i][j] = MEM[i][j+1]
                elif pattern[j+1] == '*':
                    MEM[i][j] = MEM[i][j+1]
                else:
                    MEM[i][j] = MEM[i+1][j]
            else:
                MEM[i][j] = False

    return MEM[0][0]


pattern = "ab*c"
text = "abfgmc"
res = wildcard_matcher(pattern, text)
print(res)

pattern = "ab*"
text = "abfgmc"
res = wildcard_matcher(pattern, text)
print(res)

pattern = "ab*ln"
text = "abfgdlm"
res = wildcard_matcher(pattern, text)
print(res)

pattern = "ab**ln"
text = "abfgdlm"
res = wildcard_matcher(pattern, text)
print(res)


pattern = "*ab**ln"
text = "abfgdln"
res = wildcard_matcher(pattern, text)
print(res)


pattern = "*ab**ln"
text = "fgdabfgdln"
res = wildcard_matcher(pattern, text)
print(res)


pattern = "*ab**ln"
text = "fgdafgdln"
res = wildcard_matcher(pattern, text)
print(res)
