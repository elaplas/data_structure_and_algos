



def best_time_a(arr):

    ptr_min = ptr_max = 0
    max_profit = 0

    for i in range(len(arr)):
        if arr[i] < arr[ptr_min]:
            ptr_min = i
            if ptr_max > ptr_min and arr[ptr_max]-arr[ptr_min] > max_profit:
                max_profit = arr[ptr_max]-arr[ptr_min]
            
        if arr[i] > arr[ptr_max]:
            ptr_max = i
            if ptr_max > ptr_min and arr[ptr_max]-arr[ptr_min] > max_profit:
                max_profit = arr[ptr_max]-arr[ptr_min]

    return max_profit


def best_time_b(arr):

    ptr_min = 0
    max_profit = 0

    for i in range(1, len(arr)):

        if arr[i]-arr[ptr_min] > max_profit:
            max_profit = arr[i]-arr[ptr_min]

        if arr[i] < arr[ptr_min]:
            ptr_min = i

    return max_profit


arr = [100, 200, 150, 50, 700, 800, 500]
res = best_time_a(arr)
print(res)


arr = [100, 200, 150, 50, 700, 800, 20, 120]
res = best_time_b(arr)
print(res)