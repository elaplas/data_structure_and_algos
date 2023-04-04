#!/usr/bin/env python
# coding: utf-8

# ## Reverse Polish Notation
# 
# **Reverse Polish notation**, also referred to as **Polish postfix notation** is a way of laying out operators and operands. 
# 
# When making mathematical expressions, we typically put arithmetic operators (like `+`, `-`, `*`, and `/`) *between* operands. For example: `5 + 7 - 3 * 8`
# 
# However, in Reverse Polish Notation, the operators come *after* the operands. For example: `3 1 + 4 *`
# 
# The above expression would be evaluated as `(3 + 1) * 4 = 16`
# 
# The goal of this exercise is to create a function that does the following:
# * Given a *postfix* expression as input, evaluate and return the correct final answer. 
# 
# **Note**: In Python 3, the division operator `/` is used to perform float division. So for this problem, you should use `int()` after every division to convert the answer to an integer.

# In[2]:


class LinkedListNode:

    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:

    def __init__(self):
        self.num_elements = 0
        self.head = None

    def push(self, data):
        new_node = LinkedListNode(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.num_elements += 1

    def pop(self):
        if self.is_empty():
            return None
        temp = self.head.data
        self.head = self.head.next
        self.num_elements -= 1
        return temp

    def top(self):
        if self.head is None:
            return None
        return self.head.data

    def size(self):
        return self.num_elements

    def is_empty(self):
        return self.num_elements == 0


# In[6]:


def evaluate_post_fix(input_list):
    """
    Evaluate the postfix expression to find the answer

    Args:
       input_list(list): List containing the postfix expression
    Returns:
       int: Postfix expression solution
    """
    # TODO: Iterate over elements 
    
    # TODO: Use stacks to control the element positions
    
    st = Stack()
    for s in input_list:
        if s != '+' and s != '-' and s != '/' and s != '*':
            st.push(s)
        else:
            op2 = int(st.pop())
            op1 = int(st.pop())
            res = None
            if s == '+':
                res = op1 + op2
            elif s == '-':
                res = po1 - op2
            elif s == '/':
                res = int(op1 / op2)
            elif s == '*':
                res = op1 * op2
            st.push(res)
    
    if st.size():
        return st.pop()
    else:
        return None


# In[7]:


def test_function(test_case):
    output = evaluate_post_fix(test_case[0])
    print(output)
    if output == test_case[1]:
        print("Pass")
    else:
        print("Fail")


# In[8]:


test_case_1 = [["3", "1", "+", "4", "*"], 16]

test_function(test_case_1)


# In[9]:


test_case_2 = [["4", "13", "5", "/", "+"], 6]
test_function(test_case_2)


# In[10]:


test_case_3 = [["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"], 22]
test_function(test_case_3)


# <span class="graffiti-highlight graffiti-id_wble8ty-id_56fruru"><i></i><button>Show Solution</button></span>
