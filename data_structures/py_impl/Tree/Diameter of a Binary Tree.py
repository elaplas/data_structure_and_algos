#!/usr/bin/env python
# coding: utf-8

# ## Problem statement
# 
# Given the root of a binary tree, find the diameter.
# 
# Diameter of a Binary Tree is the maximum distance between any two nodes. The distance is measured by the number of edges between the two nodes.
# 
# Diameter for a particular BinaryTree Node will be the maximum of:
# 1. Either diameter of left subtree
# 2. Or diameter of a right subtree
# 3. Or sum of left-height and right-height

# In[7]:


class BinaryTreeNode:

    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data


# In[39]:


def diameter_of_binary_tree(root):
    """
    :param: root - Root of binary tree
    TODO: Complete this method and return diameter (int) of binary tree
    """
    left_dia = 0
    right_dia = 0
    #if root.left:
    #     left_dia = diameter_of_sub_tree(root.left)
    
    
    if root.right:
        print(root.right.left)
        print(root.right.right)
        right_dia = diameter_of_sub_tree(root.right)
        
    return left_dia + right_dia


def diameter_of_sub_tree(node):
    if not node.left and not node.right:
        return 0
    
    if node.left:
        height_left, diameter_left = diameter_of_sub_tree(node.left)
    
    if node.right:
        height_right, diameter_right = diameter_of_sub_tree(node.right)
        
    current_height = max(num_left, num_right)
    current_diameter = max(left_height + right_height, left_diameter, right_diameter )
    
    return current_height, current_diameter
    


# You can use the following function to test your code with custom test cases. The function `convert_arr_to_binary_tree` takes an array input representing level-order traversal of the binary tree.
# 
# 
# <img src='./resources/01-binary-tree.png'>
# 
# **Representing the binary tree with a Python list**
# 
# The above tree would be represented as `arr = [1, 2, 3, 4, None, 5, None, None, None, None, None]`
# 
# Notice that the level order traversal of the above tree would be `[1, 2, 3, 4, 5]`. 
# 
# Note the following points about this tree:
# * `None` represents the lack of a node. For example, `2` only has a left node; therefore, the next node after `4` (in level order) is represented as `None`
# * Similarly, `3` only has a left node; hence, the next node after `5` (in level order) is represted as `None`.
# * Also, `4` and `5` don't have any children. Therefore, the spots for their children in level order are represented by four `None` values (for each child of `4` and `5`).
# 
# **Diameter of Binary Tree**
# 
# In this example, the diameter of this binary tree is for since the height of the left child is two and the height of the right child is also 2.

# In[9]:


from queue import Queue

def convert_arr_to_binary_tree(arr):
    """
    Takes arr representing level-order traversal of Binary Tree 
    """
    index = 0
    length = len(arr)
    
    # check if the array is valid. If not, return None
    if length <= 0 or arr[0] == -1:
        return None

    # instantiate the root tree from the first element of the array
    root = BinaryTreeNode(arr[index])
    # increment the index of the array
    index += 1
    # instantiate a queue and add root node to the queue
    queue = Queue()
    queue.put(root)
    
    while not queue.empty():
        # get and remove the first element from the queue
        current_node = queue.get()
        # instantiate a left child from the array's current index
        left_child = arr[index]
        # move on to the next index
        index += 1
        
        if left_child is not None:
            # instantiate a binary tree node and append as left child
            left_node = BinaryTreeNode(left_child)
            current_node.left = left_node
            # add the left node to the queue
            queue.put(left_node)
        
        # instantiate the right child from the next element in the array
        right_child = arr[index]
        # move on to the next index
        index += 1
        
        if right_child is not None:
            # instantiate a binary tree node and append as left child
            right_node = BinaryTreeNode(right_child)
            current_node.right = right_node
            # add the right node to the queue
            queue.put(right_node)
            
    return root


# In[ ]:


# Solution
def diameter_of_binary_tree(root):
    return diameter_of_binary_tree_func(root)[1]
    
def diameter_of_binary_tree_func(root):
    """
    Diameter for a particular BinaryTree Node will be:
        1. Either diameter of left subtree
        2. Or diameter of a right subtree
        3. Or sum of left-height and right-height
    :param root:
    :return: [height, diameter]
    """
    # create a base line for the recursive call
    if root is None:
        return 0, 0

    # traverse the left child recursively
    left_height, left_diameter = diameter_of_binary_tree_func(root.left)
    # traverse the right child recursively
    right_height, right_diameter = diameter_of_binary_tree_func(root.right)

    # count each height of the left and right children and get the maximum height
    current_height = max(left_height, right_height) + 1
    # calculate the diameter by summing both left and right heights
    height_diameter = left_height + right_height    
    # get the maximum value of the left or right diameter or the sum of both heights
    current_diameter = max(left_diameter, right_diameter, height_diameter)

    return current_height, current_diameter


# In[10]:


def test_function(test_case):
    arr = test_case[0]
    solution = test_case[1]
    root = convert_arr_to_binary_tree(arr)
    output = diameter_of_binary_tree(root)
    print(output)
    if output == solution:
        print("Pass")
    else:
        print("Fail")


# In[38]:


arr = [1, 2, 3, 4, 5, None, None, None, None, None, None]
solution = 3

test_case = [arr, solution]
test_function(test_case)


# In[ ]:


arr = [1, 2, 3, 4, None, 5, None, None, None, None, None]
solution = 4

test_case = [arr, solution]
test_function(test_case)


# In[ ]:


arr = [1, 2, 3, None, None, 4, 5, 6, None, 7, 8, 9, 10, None, None, None, None, None, None, 11, None, None, None]
solution = 6

test_case = [arr, solution]
test_function(test_case)


# In[ ]:


arr = [1, 2, 3, 4, None, 5, None, None, None, None, None]
solution = 4

test_case = [arr, solution]
test_function(test_case)


# In[ ]:




