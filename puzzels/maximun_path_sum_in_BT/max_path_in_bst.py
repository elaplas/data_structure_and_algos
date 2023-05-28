

def find_max_in_BT(root):
    res = [0]
    find_max_in_BT_helper(root, res)
    return res[0]


def find_max_in_BT_helper(node, res):
    if not node:
        return

    if node.left:
        find_max_in_BT_helper(node.left, res)

    if node.right:
        find_max_in_BT_helper(node.right, res)

    if node.value < 0:
        res[0] = 0
    else:
        res[0] += node.value

    
def find_max_in_bt(root):
        
    if not root:
        return 0
    l_val = find_max_in_bt(root.left)
    r_val = find_max_in_bt(root.right)
    return max(root.value, 
                root.value + l_val, 
                root.value + r_val, 
                root.value + l_val + r_val)
    
class Node:
    def __init__(self, val = None):
        self.value = val
        self.left = None
        self.right = None
    
root = Node(20)
root.left = Node(10)
root.right = Node(30)
root.left.left = Node(-15)
root.left.left.right = Node(5)


res = find_max_in_BT(root)
print(res)

res = find_max_in_bt(root)
print(res)

