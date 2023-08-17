class Node:
    def __init__(self, k=None, v=None):
        self.value = v
        self.key = k
        self.next = None


class Map:

    def __init__(self):
        self.__load_factor = 0.7
        self.__capacity = 10
        self.__num_entries = 0
        self.__buckets = [None for _ in range(self.__capacity)]


    def __getitem__(self, key):
        hashed_key = self.__get_hash_code(key)
        curNode = self.__buckets[hashed_key]
        while curNode:
            if curNode.key == key:
                return curNode.value
            curNode = curNode.next
        return None
        

    def __setitem__(self, key, val):
        
        self.__num_entries += 1
        if (self.__num_entries/self.__capacity) > self.__load_factor:
            self.__rehash(self.__capacity * 2)
        hashed_key = self.__get_hash_code(key)
        if self.__buckets[hashed_key]:
            curNode = self.__buckets[hashed_key]
            while curNode.next:
                curNode = curNode.next
            curNode.next = Node(key, val)
        else:
            self.__buckets[hashed_key] = Node(key, val)

    def __iter__(self):
        for bucket in self.__buckets:
            curNode = bucket
            while curNode:
                yield curNode.key
                curNode = curNode.next


    def erase(self, key):
        hashed_key = self.__get_hashed_key(key)
        bucket = self.__buckets[hashed_key]
        curNode = bucket
        preNode = None
        while curNode:
            if curNode.key == key:
                if curNode == bucket:
                    bucket = curNode.next
                else:
                    preNode.next = curNode.next
                break
            preNode = curNode
            curNode = curNode.next

    def __rehash(self, new_capacity):
        tmp = self.__buckets
        self.__capacity = new_capacity
        self.__buckets = [None for _ in range(new_capacity)]
        for bucket in tmp:
            curNode = bucket
            while curNode:
                self[curNode.key] = curNode.value
                curNode = curNode.next

    def __get_hash_code(self, key):
        hashed_key = 0
        factor = 1
        for i in range(len(key)-1, -1, -1):
            num = ord(key[i])-97
            hashed_key += ( num * factor)
            factor *= 31
        return hashed_key%self.__capacity
    
    def __repr__(self):
        str_x = ""
        for i in range(len(self.__buckets)):
            str_x += f"[{i}]"
            if self.__buckets[i]:
                cur_node = self.__buckets[i]
                while cur_node:
                    str_x += f"---> {cur_node.key, cur_node.value} "
                    cur_node = cur_node.next
            str_x += "\n"
        return str_x



map = Map()

map["ebi"] = 194
map["sara"] = 176
map["sina"] = 178
map["ali"] = 188
map["bahman"] = 190
map["armin"] = 170
map["sanaz"] = 171
map["susan"] = 111
map["xi"] = 145
map["ebra"] = 120
map["amin"] = 189
map["saman"] = 149

print(map)