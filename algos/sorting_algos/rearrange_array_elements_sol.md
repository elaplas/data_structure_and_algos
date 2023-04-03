# Problem 3
## Decisions
First the list is sorted in ascending order using merge-sort algorithm and then the two biggest digits are taken from the sorted list and call them "first and second numbers". Afterwards the other digits are taken sequentially from the end of the list and multiplied with ten and added to "first and second numbers" respectively.  
## Time efficiency
O(n) + O(n*logn) ~ O(n*logn) where n is the size of list

## Space efficiency
O(n) where n is the size of list