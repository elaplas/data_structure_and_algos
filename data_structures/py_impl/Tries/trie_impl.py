class TrieNode:
    def __init__(self, val = None, is_terminated=False):
        self.terminated = is_terminated
        self.value = val
        self.nodes = {}
    
    def add_node(self, key, val = None, is_terminated=False):
        if key not in self.nodes:
            self.nodes[key]= TrieNode(val, is_terminated)

        return self.nodes[key]    

    def get_node(self, key):
        if key in self.nodes:
            return self.nodes[key]
        else:
            return None


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add_word(self, word):

        cur_node = self.root
        for i in range(len(word)):
            if i == len(word)-1:
                cur_node = cur_node.add_node(word[i], is_terminated=True)
            else:
                cur_node= cur_node.add_node(word[i], is_terminated=False)
    
    def find_word(self, word):

        cur_node = self.root
        for i in range(len(word)):

            res = cur_node.get_node(word[i])

            if not res:
                return -1
            else:
                cur_node = res

            if i == len(word)-1:
                if cur_node.terminated:
                    return cur_node
                else:
                    return -1

    
    def suffix(self, prefix):

        cur_node = self.find_word(prefix)

        res = []
        if cur_node == -1:
            return res

        self._suffix_recursive(cur_node, prefix, res)

        return res

    
    def _suffix_recursive(self, cur_node, cur_suffix, suffixes):
        
        if cur_node.terminated:
            suffixes.append(cur_suffix)
        
        for key in cur_node.nodes:
            self._suffix_recursive(cur_node.nodes[key], cur_suffix+key, suffixes)

        


trie = Trie()
trie.add_word("ab")
trie.add_word("abc")
trie.add_word("abd")
trie.add_word("abcf")
trie.add_word("abcg")
trie.add_word("abdl")
trie.add_word("abdm")

print(".................")
res = trie.suffix("ab")
print(res)
print(".................")
res = trie.suffix("abc")
print(res)
print(".................")