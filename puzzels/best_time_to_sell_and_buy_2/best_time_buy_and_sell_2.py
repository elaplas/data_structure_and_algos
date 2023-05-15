

def best_time(arr):

    min_ptr = max_ptr = 0
    profit = 0
    for i in range(1, len(arr)):

        if arr[i] < arr[i-1]:
            profit += (arr[max_ptr] - arr[min_ptr])
            min_ptr = max_ptr = i
        
        if arr[i] > arr[i-1]:
            max_ptr = i

    return profit
        

arr = [30, 20, 10, 35, 50, 100, 90, 40, 20, 50, 80, 30, 10]
res = best_time(arr)
print(res)

arr=[100, 200, 150, 50, 700, 800, 500]
res = best_time(arr)
print(res)