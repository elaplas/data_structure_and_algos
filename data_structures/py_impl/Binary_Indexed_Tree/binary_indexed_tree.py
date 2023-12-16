
class BIT:
    def __init__(self, arr):
        self.arr = arr
        self.tree = [0 for _ in range(len(arr)+1)]
        self.construct()

    # Returns least significant bit e.g. lsb of "101" is "001". 
    # It considers the most left non-zero bit and ignores all others
    def lsb(self, i):
        return i & (-i)

    def construct(self):
        for i in range(len(self.arr)):
            index = i+1
            while index < len(self.tree):
                self.tree[index] += self.arr[i]
                index += self.lsb(index)

    def update(self, i, value):
        diff = value - self.query(i, i)
        index = i+1
        self.arr[i] += diff
        while index < len(self.tree):
            self.tree[index] += diff
            index += self.lsb(index)
    
    def query(self, start_range, end_range):
        sum_start = self.query_bit(start_range-1)
        sum_end = self.query_bit(end_range)
        return sum_end - sum_start

    def query_bit(self, end_range):
        index = end_range + 1 
        s = 0
        while index > 0:
            s += self.tree[index]
            index -= self.lsb(index)
        return s



arr = [1,2,3,4,5]
bit = BIT(arr)
print("array: ", bit.arr)
print("binary indexed tree:", bit.tree)
res = bit.query(0, 0)
print(res)
res = bit.query(0, 1)
print(res)
res = bit.query(0, 2)
print(res)
res = bit.query(0, 3)
print(res)
res = bit.query(0, 4)
print(res)
print("... after update ...")
bit.update(2, -3)
print("array: ", bit.arr)
print("binary indexed tree:", bit.tree)
res = bit.query(0, 0)
print(res)
res = bit.query(0, 1)
print(res)
res = bit.query(0, 2)
print(res)
res = bit.query(0, 3)
print(res)
res = bit.query(0, 4)
print(res)