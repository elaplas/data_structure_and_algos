# Problem 2
## Decisions
First the index of pivot is found by dividing recursively the array by two. If the left side of the array is sorted correctly then it is discarded and the right side becomes the array we will search for the pivot. The same procedure is repeated untill we find the pivot. Once the pivot is found, the array is split in two parts in the pivot index and passed to a binary search algo to lookup for the target number. 
## Time efficiency
- pivot search: O(logn)
- binary search: O(logn)
- O(logn) ~ O(logn) + 2*O(logn)
## Space efficiency
O(1)