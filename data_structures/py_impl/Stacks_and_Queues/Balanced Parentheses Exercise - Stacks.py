#!/usr/bin/env python
# coding: utf-8

# # Balanced Parentheses Exercise

# In this exercise you are going to apply what you learned about stacks with a real world problem. We will be using stacks to make sure the parentheses are balanced in mathematical expressions such as: $((3^2 + 8)*(5/2))/(2+6).$ In real life you can see this extend to many things such as text editor plugins and interactive development environments for all sorts of bracket completion checks. 
# 
# Take a string as an input and return `True` if it's parentheses are balanced or `False` if it is not. 
# 
# Try to code up a solution and pass the test cases. 

# #### Code

# In[1]:


# Our Stack Class - Brought from previous concept
# No need to modify this
class Stack:
    def __init__(self):
        self.items = []
    
    def size(self):
        return len(self.items)
    
    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.size()==0:
            return None
        else:
            return self.items.pop()

def equation_checker(equation):
    """
    Check equation for balanced parentheses

    Args:
       equation(string): String form of equation
    Returns:
       bool: Return if parentheses are balanced or not
    """
    
    
    # TODO: Intiate stack object
    
    # TODO: Interate through equation checking parentheses
    
    # TODO: Return True if balanced and False if not
    
    st = Stack()
    for s in equation:
        if s == '(' or s == '[':
            st.push(s)
        if s == ')' :
            tmp = st.pop()
            if tmp != '(':
                return False
        if s == ']':
            tmp = st.pop()
            if tmp != '[':
                return False
    return True
                


# #### Test Cases

# In[2]:


print ("Pass" if (equation_checker('((3^2 + 8)*(5/2))/(2+6)')) else "Fail")
print ("Pass" if not (equation_checker('((3^2 + 8)*(5/2))/(2+6))')) else "Fail")


# In[ ]:


# Solution

# Our Stack Class
class Stack:
    def __init__(self):
        self.items = []

    def size(self):
        return len(self.items)

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.size()==0:
            return None
        else:
            return self.items.pop()


def equation_checker(equation):
    """
    Check equation for balanced parentheses

    Args:
       equation(string): String form of equation
    Returns:
       bool: Return if parentheses are balanced or not
    """
    
    stack = Stack()

    for char in equation:
        if char == "(":
            stack.push(char)
        elif char == ")":
            if stack.pop() == None:
                return False

    if stack.size() == 0:
        return True
    else:
        return False


print ("Pass" if (equation_checker('((3^2 + 8)*(5/2))/(2+6)')) else "Fail")
print ("Pass" if not (equation_checker('((3^2 + 8)*(5/2))/(2+6))')) else "Fail")


# <span class="graffiti-highlight graffiti-id_ky3qi6e-id_jfute45"><i></i><button>Show Solution</button></span>

# In[ ]:




