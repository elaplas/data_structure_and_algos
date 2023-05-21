

""" 
Problem:

1- Find kth smallest node of BST?
2- Sort an array using a BST?

"""

class Node:
    def __init__(self, val = None):
        self.value = val
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None
    
    def add_node(self, value):

        if not self.root:
            self.root = Node(value)
            return
        
        cur_node = self.root

        while cur_node:

            if value < cur_node.value:
                if cur_node.left:
                    cur_node = cur_node.left
                else:
                    cur_node.left = Node(value)
                    break
            else:
                if cur_node.right:
                    cur_node = cur_node.right
                else:
                    cur_node.right = Node(value)
                    break


def kth_smallest_node(root, k):
    ref_k = [k]
    ref_res = [None]
    kth_smallest_node_helper(root, ref_k, ref_res)
    return ref_res[0]

def kth_smallest_node_helper(root, k, res):
    
    if not root:
        return
    
    if root.left:
        kth_smallest_node_helper(root.left, k, res)
    
    k[0] -= 1

    if k[0]==0:
        res[0] = root
        return
    
    if root.right:
        kth_smallest_node_helper(root.right, k, res)

def sort_tree(root):
    result = []
    sort_tree_help(root, result)
    return result

def sort_tree_help(node, result):
    if not node:
        return
    
    if node.left:
        sort_tree_help(node.left, result)
    
    result.append(node.value)

    if node.right:
        sort_tree_help(node.right, result)



tree = Tree()
tree.add_node(3)
tree.add_node(4)
tree.add_node(1)
tree.add_node(6)
tree.add_node(7)
tree.add_node(2)

node = kth_smallest_node(tree.root, 3)
print(node.value)

node = kth_smallest_node(tree.root, 5)
print(node.value)

res = sort_tree(tree.root)
print(res)
