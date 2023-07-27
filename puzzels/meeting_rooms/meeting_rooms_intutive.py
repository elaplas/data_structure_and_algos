

# Given N meeting timings, with their start time and end time (both inclusive), the task
# is to find the minimum number of rooms required to hold all the meetings such that a single
# meeting can be used for only one lecture at a given time


# idea: group the meetings that dont have any conflicts. Start with one group containing only one meeting. Afterwards 
# traverse through meetings and if a meeting doesn't have any conflicts with a group, add it to that group, otherwise 
# creates a new group and put the meeting in it. The group members and group number are updated during the iterations. 
# The number of groups is the minimum of rooms needed to hold the meetings without conflicts.  

def min_meeting_rooms(list_intervals):

    res = min_meeting_rooms_helper(list_intervals, 0)
    return len(res)


def conflicted(interval_a, interval_b):

    return interval_b[0] < interval_a[1] and interval_b[1] > interval_a[0]


def min_meeting_rooms_helper(list_intervals, i):

    if i == len(list_intervals)-1:

        return [[i]]
    
    interval_groups = min_meeting_rooms_helper(list_intervals, i+1)

    for interval_group in interval_groups:
        conflict = False
        for interval in interval_group:
            
            if conflicted(list_intervals[interval], list_intervals[i]):
                conflict = True
                break
        
        if not conflict:
            interval_group.append(i)
            return interval_groups
    
    interval_groups.append([i])

    return interval_groups




list_intervals = [ [0, 30], [5, 10], [15, 20]]
res = min_meeting_rooms(list_intervals)
print(res)

list_intervals =  [ [1, 18], [18, 23], [15, 29], [4, 15], [2, 11], [5, 13] ]
res = min_meeting_rooms(list_intervals)
print(res)