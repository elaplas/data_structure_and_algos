# Problem 6
## Decisions
The problem can be solved by walking through the first list and compare each of its elements with the whole elements in the second, which leads to O(n2). In addition, it can end up with a complex logic to get ride of repetitive elements if we stick to constant space complexity. However if two "sets" are used, we need only to walk through the first and second lists one time and the repetitive elements are eliminated themselves.
## Time efficiency
O(n) ~ O(2 * n1) + O(2 * n2) where n1 and 2n are the length of the lists, the number "2" is because of walking through the corresponding "set" data structure.
## Space efficiency
O(n) ~ O(n1) + O(n2) where n1 and n2 are the length of the corresponding "set" data structures