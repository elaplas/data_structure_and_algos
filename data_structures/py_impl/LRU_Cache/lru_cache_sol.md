# Problem 1
## Decisions
A "map" data structure is used to store the key and (value, node) pair where node is the reference of the node used for updating the "likedlist" data structure faster. If we don't store the reference of the nod in the  "map" then we need to walk through the whole "linkedlist". The "linkedlist" is used to keep tracking of using frequency of (key, value) pair. 
## Time efficiency
- Set: O(1)
- Get: o(1)
## Space efficiency
O(n) ~ O(n<sub>1</sub>) + O(n<sub>2</sub>) where n<sub>1</sub> and n<sub>2</sub> are the length of the "linkedlist" and "map" data structures