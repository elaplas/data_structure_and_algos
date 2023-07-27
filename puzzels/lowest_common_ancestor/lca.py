
# Given a binary tree, and two values v1 and v2, find the lowest common ancestor of nodes with their values as v1 and v2.
# 
# Where the lowest common ancestor of two nodes (Node1 and Node2) is the deepest node of which Node1 and Node2 are descendants. Note that here we consider that a node is the descendant of itself also.
# Examples
# Example 1 -
# 
# Input - Given Tree -
# 
# 	    1
# 	   / \
# 	  /   \
# 	 2     3
# 	/ \     \
#        /   \     \
#       4     5     6
#        \         / \
#         \       /   \
#          7     8     9
#
#
# LCA Queries -
#
#    LCA (4, 5)
#    LCA (7, 4)
#    LCA (5, 8)
#
#
#
# Output -
#
# LCA of 4 and 5 is 2
# LCA of 7 and 4 is 4
# LCA of 5 and 8 is 1


class Node:
    def __init__(self, val):
        self.value = val
        self.left = None
        self.right = None


def LCA(root, val1, val2):
    return LCA_helper(root, val1, val2)


def LCA_helper(node, val1, val2):

    if not node:
        return None
    

    left_target = LCA_helper(node.left, val1, val2)
    right_target = LCA_helper(node.left, val1, val2)

    # One of the targets is found
    if node.value == val1 or node.value == val2:
        return node
    
    # LCA is found
    if left_target and right_target:
        return node
    
    if left_target and not right_target:
        return left_target
    
    if right_target and not left_target:
        return right_target