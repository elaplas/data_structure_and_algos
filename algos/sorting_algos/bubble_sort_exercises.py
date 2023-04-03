#!/usr/bin/env python
# coding: utf-8

# # Bubble Sort Exercises
# Now that you know how about bubble sort works, you'll implement bubble sort for two exercises.

# ## Exercise 1

# Sam records when they wake up every morning. Assuming Sam always wakes up in the same hour, use bubble sort to sort by earliest to latest.
# 
# 

# In[4]:


wakeup_times = [16,49,3,12,56,49,55,22,13,46,19,55,46,13,25,56,9,48,45]
def bubble_sort_1(in_list):
    # TODO: Implement bubble sort solution
    num_iterations = 0
    num_comparsions = len(in_list)-1 
    
    while num_iterations < len(in_list)-1:
        for i in range(num_comparsions):
            if in_list[i] > in_list[i+1]:
                tmp = in_list[i]
                in_list[i] = in_list[i+1]
                in_list[i+1] = tmp
        
        num_iterations += 1
        num_comparsions -= 1
        

bubble_sort_1(wakeup_times)
print(wakeup_times)
print ("Pass" if (wakeup_times[0] == 3) else "Fail")


# <span class="graffiti-highlight graffiti-id_y26wn0b-id_uppmlq4"><i></i><button>Hide Solution</button></span>

# In[ ]:


def bubble_sort_1(l):
    for iteration in range(len(l)):
        for index in range(1, len(l)):
            this = l[index]
            prev = l[index - 1]

            if prev <= this:
                continue

            l[index] = prev
            l[index - 1] = this


# ## Exercise 2

# Sam doesn't always go to sleep in the same hour. Given the following times Sam has gone to sleep, sort the times from latest to earliest.

# In[8]:


# Entries are (h, m) where h is the hour and m is the minute
sleep_times = [(24,13), (21,55), (23,20), (22,5), (24,23), (21,58), (24,3)]

def bubble_sort_2(l):
    # TODO: Implement bubble sort solution
    num_iterations = 0
    num_comparisons = len(l) - 1
    
    while num_iterations < len(l):
        for i in range(num_comparisons):
            if (l[i][0] < l[i+1][0]) or (l[i][0] == l[i+1][0] and l[i][1] < l[i+1][1] ):
                tmp = l[i]
                l[i] = l[i+1]
                l[i+1] = tmp
            
        num_iterations += 1
        num_comparisons -= 1

bubble_sort_2(sleep_times)
print(sleep_times)
print ("Pass" if (sleep_times == [(24,23), (24,13), (24,3), (23,20), (22,5), (21,58), (21,55)]) else "Fail")


# <span class="graffiti-highlight graffiti-id_f6s1i29-id_hxr8nmt"><i></i><button>Show Solution</button></span>
