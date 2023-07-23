#Given a set of non-overlapping intervals and a new interval.
#
#Insert the new interval into the set of intervals (merge if necessary).
#
#You may assume that the intervals were initially sorted according to their start times.
#Note: Make sure the returned intervals are also sorted.


# Intervals = [[1,3],[6,9]]
# newInterval = [2,5]           ----------> [[1,5],[6,9]]

# Intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
# newInterval = [4,9]                                ----------> [[1,2],[3,10],[12,16]]
# 

def merge_intervals(intervals, new_interval):

    res = []

    for interval in intervals:


        if len(new_interval):

            if interval[1] > new_interval[0] and interval[0] < new_interval[1]:
                
                # Merge intervals
                if interval[0] < new_interval[0]:
                    new_interval[0] = interval[0]
            
                if interval[1] > new_interval[1]:
                    new_interval[1] = interval[1]
            else:
                # Push back intervals and new interval into result
                if interval[1] < new_interval[0]:
                    res.append(interval)
                elif interval[0] > new_interval[1]:
                    res.append(new_interval)
                    res.append(interval)
                    new_interval = []
        else:
            res.append(interval)

    if len(new_interval):
        res.append(new_interval)

    return res

intervals =  [[1,2],[3,5],[6,7],[8,10],[12,16]]
new_interval = [4,9]     
res = merge_intervals(intervals, new_interval)
print(res)

intervals = [[1,3],[6,9]]
new_interval = [2,5]          
res = merge_intervals(intervals, new_interval)
print(res)