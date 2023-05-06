
class Node:
    def __init__(self, k = None, v = None):
        self.key = k
        self.value = v
        self.next = None


class Map:
    def __init__(self):
        self.bucket = [None for _ in range(10)]
        self.size = 0

    def __setitem__(self,key, value):
        bucket_index = self.hash_function(key)
        if not self.bucket[bucket_index]:
            self.bucket[bucket_index] = Node(key, value)
        else:
            cur_node = self.bucket[bucket_index]
            while cur_node.next:
                cur_node = cur_node.next
            cur_node.next = Node(key, value)  
        self.size += 1

    def __getitem__(self, key):
        bucket_index = self.hash_function(key)
        if not self.bucket[bucket_index]:
            return None
        else:
            cur_node = self.bucket[bucket_index]
            while cur_node:
                if cur_node.key == key:
                    return cur_node.value
                cur_node = cur_node.next
        return 
        
    def __iter__(self):
        for i in range(len(self.bucket)):
            if self.bucket[i]:
                cur_node = self.bucket[i]
                while cur_node:
                    yield cur_node.key
                    cur_node = cur_node.next

    def remove(self, key):
        hash_code = self.hash_function(key)
        if self.bucket[hash_code]:
            head = self.bucket[hash_code]
            if head.key == key:
                self.bucket[hash_code] = head.next
            else:
                cur_node = head
                pre_node = None
                while cur_node.next:
                    if cur_node.key == key:
                        pre_node.next = cur_node.next
                    pre_node = cur_node 
                    cur_node = cur_node.next

    def hash_function(self, key):
        if type(key) == str:
            base = 1
            hash_code = 0
            for i in range(len(key)-1, 0, -1):
                dig = ord(key[i])
                hash_code += dig * base
                base *= 31
            return hash_code % len(self.bucket)
    
    def __repr__(self):
        str_x = ""
        for i in range(len(self.bucket)):
            str_x += f"[{i}]"
            if self.bucket[i]:
                cur_node = self.bucket[i]
                while cur_node:
                    str_x += f"---> {cur_node.key, cur_node.value} "
                    cur_node = cur_node.next
            str_x += "\n"
        return str_x

        
print("--------------put key-value pairs in map---------------")
map = Map()
map["ebi"] = 195
map["sara"] = 185
map["reza"] = 186
map["ali"] = 184
map["mahsa"] = 183
map["mamad"]  = 182
print(map)
print("--------------iterate through map---------------")
for key in map:
    print(key,": ",map[key])
print("-----------remove mahsa------------------")
map.remove("mahsa")
print(map)
print("-----------remove ebi------------------")
map.remove("ebi")
print(map)
print("-----------------------------")