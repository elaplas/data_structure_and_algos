
class Node:
    def __init__(self, val):
        self.next = None
        self.previous = None
        self.value = val

class DoublyLikedList:
    def __init__(self):
        self.front = None
        self.back = None
        self.size = 0

    def size(self):
        return self.size

    def push_back(self, val):
        if self.front is None:
            self.front = self.back = Node(val)
            
        else:
            self.back.next = Node(val)
            self.back.next.previous = self.back
            self.back = self.back.next
        
        self.size += 1

    def pop_front(self):
        if self.front is None:
            return None

        tmp = self.front.value
        self.front = self.front.next
        self.front.previous = None
        self.size -= 1
        return tmp

    def delete_node(self, node):

        if node == self.front:
            return self.pop_front()
        else:
            next = node.next 
            previous = node.previous

            if next:
                next.previous =  node.previous

            if previous:
                previous.next = node.next
            
            self.size -= 1
            return node.value


class Element:
    def __init__(self, val = None, node = None):
        self.value = val
        self.node = node
    

class LRU_Cache(object):

    def __init__(self, capacity):
        # Initialize class variables
        self.capacity = capacity
        self.size = 0
        self.history = {}
        self.recently_used = DoublyLikedList()

    def get(self, key):
        # Retrieve item from provided key. Return -1 if nonexistent. 
        if key in self.history:
            element = self.history[key]
            self.recently_used.delete_node(element.node)
            self.recently_used.push_back(key)
            element.node = self.recently_used.back
            return element.value

        else:
            return -1

    def set(self, key, value):
        # Set the value if the key is not present in the cache. If the cache is at capacity remove the oldest item. 
        self.recently_used.push_back(key) 
        self.history[key] = Element(value, self.recently_used.back)
        self.size += 1

        if self.size > self.capacity:
            deleted_key = self.recently_used.pop_front()
            self.history.pop(deleted_key)



our_cache = LRU_Cache(5)

our_cache.set(1, 1)
our_cache.set(2, 2)
our_cache.set(3, 3)
our_cache.set(4, 4)


print("result: {}, expected: {}".format(our_cache.get(1), 1))       # returns 1
print("result: {}, expected: {}".format(our_cache.get(2), 2))       # returns 2
print("result: {}, expected: {}".format(our_cache.get(9), -1))      # returns -1 because 9 is not present in the cache

our_cache.set(5, 5) 
our_cache.set(6, 6)

print("result: {}, expected: {}".format(our_cache.get(3), -1))      # returns -1 because the cache reached it's capacity 
                                                                    # and 3 was the least recently used entry


# Test Case 1
our_cache.set(7,7)
print("result: {}, expected: {}".format(our_cache.get(4), -1))      # returns -1 because the cache reached it's capacity 
                                                                    # and 4 was the least recently used entry
print("result: {}, expected: {}".format(our_cache.get(7), 7))       # it returns 7

# Test Case 2
our_cache.set(8, 12000000)
print("result: {}, expected: {}".format(our_cache.get(1), -1))       # returns -1 because the cache reached it's capacity and 1
                                                                     # was the least recently used entry
print("result: {}, expected: {}".format(our_cache.get(8), 12000000)) # returns 12000000

# Test Case 3

our_cache = LRU_Cache(0)
print("result: {}, expected: {}".format(our_cache.get(100), -1))     # returns -1