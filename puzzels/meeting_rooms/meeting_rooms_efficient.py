

# Given N meeting timings, with their start time and end time (both inclusive), the task
# is to find the minimum number of rooms required to hold all the meetings such that a single
# meeting can be used for only one lecture at a given time


# idea: The maximum number of meetings that conflicts at any time instant t is the minimum number of rooms required 
# for holding the meetings without conflicts. If we sort the meetings based on their start time and end time and keep
# incrementing encountering start times and decrementing encountering end times; then, we can find the maximum number of rooms
# meeting simply by keep tracking of a counter while incrementing and decrementing.  
# 
# Example:  

#  meeting 1:  |--------------|
#  meeting 2:           |------------|
#  meeting 3:        |------|
#
# we start with counter equal to zero, then we face the starting times of meeting 1,2, and 3; so, we increment the counter by three
# then we encounter the ending time of meeting 3 and decrement the counter to 2. Afterwards the ending time of meeting 1 is encountered
# and the counter is decremented to  1 and finally the ending time of meeting 2 is met and the counter becomes zero. The maximum value
# of the counter during the traversal through sorted starting and ending times is 3, so the minimum number of rooms to hold the meeting 
# without any conflicts is 3.  

def min_meeting_rooms(list_intervals):
    
    times = []
    for interval in list_intervals:
        times.append([interval[0], 1])
        times.append([interval[1], -1])
    
    sorted_times = sorted(times)
    min_num_rooms = 0
    cur_num_conflicts = 0

    for t in sorted_times:
        cur_num_conflicts += t[1]
        if cur_num_conflicts > min_num_rooms:
            min_num_rooms = cur_num_conflicts

    return min_num_rooms


list_intervals = [ [0, 30], [5, 10], [15, 20]]
res = min_meeting_rooms(list_intervals)
print(res)

list_intervals =  [ [1, 18], [18, 23], [15, 29], [4, 15], [2, 11], [5, 13] ]
res = min_meeting_rooms(list_intervals)
print(res)