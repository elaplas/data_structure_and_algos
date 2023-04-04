#!/usr/bin/env python
# coding: utf-8

# ### Problem Statement
# 
# Given an input string consisting of only `{` and `}`, figure out the minimum number of reversals required to make the brackets balanced.
# 
# For example:
# * For `input_string = "}}}}`, the number of reversals required is `2`.
# 
# 
# * For `input_string = "}{}}`, the number of reversals required is `1`.
# 
# 
# If the brackets cannot be balanced, return `-1` to indicate that it is not possible to balance them.

# In[1]:


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


# In[5]:


def minimum_bracket_reversals(input_string):
    """
    Calculate the number of reversals to fix the brackets

    Args:
       input_string(string): Strings to be used for bracket reversal calculation
    Returns:
       int: Number of breacket reversals needed
    """
    
    # TODO: Write function here
    st = Stack()
    for s in input_string:
        if s == "{" or st.is_empty():
            st.push(s)
        elif s == "}":
            if st.top() == "{":
                st.pop()
            else:
                st.push(s)
                
    if st.size() % 2 == 0:
        return st.size() / 2
    else:
        return -1
            


# In[6]:


def test_function(test_case):
    input_string = test_case[0]
    expected_output = test_case[1]
    output = minimum_bracket_reversals(input_string)
    
    if output == expected_output:
        print("Pass")
    else:
        print("Fail")


# In[7]:


test_case_1 = ["}}}}", 2]
test_function(test_case_1)


# In[8]:


test_case_2 = ["}}{{", 2]          
test_function(test_case_2)


# In[9]:


test_case_3 = ["{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}", 13]

test_function(test_case_1)


# In[10]:


test_case_4= ["}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{", 2]
test_function(test_case_2)


# In[ ]:


def minimum_bracket_reversals(input_string):
    if len(input_string) % 2 == 1:
        return -1

    stack = Stack()
    count = 0
    for bracket in input_string:
        if stack.is_empty():
            stack.push(bracket)
        else:
            top = stack.top()
            if top != bracket:
                if top == '{':
                    stack.pop()
                    continue
            stack.push(bracket)

    ls = list()
    while not stack.is_empty():
        first = stack.pop()
        second = stack.pop()
        ls.append(first)
        ls.append(second)
        if first == '}' and second == '}':
            count += 1
        elif first == '{' and second == '}':
            count += 2
        elif first == '{' and second == '{':
            count += 1
    return count


# In[11]:


test_case_5 = ["}}{}{}{}{}{}{}{}{}{}{}{}{}{}{}", 1]

test_function(test_case_3)


# <span class="graffiti-highlight graffiti-id_nswj6h2-id_mclvpey"><i></i><button>Show Solution</button></span>
