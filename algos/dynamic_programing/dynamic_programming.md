# What is dynamic programing

Breaking a big and complex problem into smaller sub-problems; then, start solving the base case (trivial case) and storing its result in a lookup table. Afterwards by using the solution of trivial case and the lookup table we add more complexity to the solution of sub-problems. 


Dynamic programming takes advantage of these two things:
- base case 
- lookup table

A common feature of dynamic programming is the usage of an equation that 
- combines previously computed values in the lookup table with each other
- combines previously computed values in the lookup table with new values

The hidden power of dynamic programming is that we compute and store the solutions of smaller sub-problems so we don't need to calculate them again for more complex sub-problems. This can have a powerful effect on the time efficiency of the solution e.g. reducing it from exponential time complexity O(2<sup>n</sup>) to polynomial time complexity O(n<sup>2</sup>).

A very useful skill of a programer is the ability to spot a problem that has a dynamic programming solution. In case of complicated problems that require trying every combination to find the solution, you may ask yourself, can I break this problem into sub-problems and solve it by dynamic programming?

Mastering dynamic programming requires practicing bunch of problems that can be solved by dynamic programming.