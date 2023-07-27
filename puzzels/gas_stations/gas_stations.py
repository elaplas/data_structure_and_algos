

# Given two integer arrays A and B of size N.
# There are N gas stations along a circular route, where the amount of gas at station i is A[i].
# There are N gas stations
# input:
# A = [1, 2]
# B = [2, 1]
# output:
# 1
# explanation:
# If you start from index 0, you can fill in A[0] = 1 amount of gas.
# Now your tank has 1 unit of gas. But you need B[0] = 2 gas to travel to station 1.
# 
# If you start from index 1, you can fill in A[1] = 2 amount of gas.
# Now your tank has 2 units of gas. You need B[1] = 1 gas to get to station 0.
# So, you travel to station 0 and still have 1 unit of gas left over.
# You fill in A[0] = 1 unit of additional gas, making your current gas = 2.
# It costs you B[0] = 2 to get to station 1, which you do and complete the circuit.






# Given a string A and integer k, what is maximal lexicographical 
# string that can be made from A if you do atmost B swaps
# input: A = "254", k = 2
# output: "542"


# idea:
# First we calculate all possible swaps which are computed using two for loops;
# then, we try each swap recursively till we found the max swapped string. 
# The recursion is done k times (depth of recursion)  


def gas_station_helper(gas_stations, costs, start_index, cur_index, second_round, leftover ):

    if start_index == cur_index and second_round:
        return cur_index
    
    if (leftover + gas_stations[cur_index]) - costs[cur_index] < 0:
        return -1

    leftover = (leftover + gas_stations[cur_index]) - costs[cur_index] 

    if cur_index == len(gas_stations) -1:
        cur_index = 0
    else:
        cur_index += 1

    return gas_station_helper(gas_stations, costs, start_index, cur_index, True,  leftover)



def min_index_gas_station(gas_stations, costs):

    res = []
    for i in range(len(gas_stations)):
        res_i = gas_station_helper(gas_stations, costs, i, i, False, 0)
        if res_i != -1:
            res.append(res_i)

    if not len(res):
        return -1
    else:
        return sorted(res)[0]


stations = [1,2]
costs = [2,1]
res = min_index_gas_station(stations, costs)
print(res)


stations = [4, 6, 7, 4]
costs = [6, 5, 3, 5]
res = min_index_gas_station(stations, costs)
print(res)

stations = [6, 3, 7]
costs = [4, 6, 3]
res = min_index_gas_station(stations, costs)
print(res)


# Here we will use another variable to 
# substitute the extra loop from start till 
# the latest found start point. The variable will 
# store the sum of utilized petrol from 0 till the 
# latest start petrol pump.

def min_index_gas_station_single_loop(stations, costs):

    leftover = 0
    start_index = 0
    deficit = 0

    for i in range(len(stations)):

        leftover += (stations[i] - costs[i])

        if leftover < 0:
            start_index = (i+1)
            deficit += leftover
            leftover = 0
        
    if leftover < 0:
        return -1
    else:
        return start_index
    

stations = [1,2]
costs = [2,1]
res = min_index_gas_station_single_loop(stations, costs)
print(res)


stations = [4, 6, 7, 4]
costs = [6, 5, 3, 5]
res = min_index_gas_station_single_loop(stations, costs)
print(res)

stations = [6, 3, 7]
costs = [4, 6, 3]
res = min_index_gas_station_single_loop(stations, costs)
print(res)
