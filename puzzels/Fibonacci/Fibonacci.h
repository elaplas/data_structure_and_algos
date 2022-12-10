#ifndef FIBONACCI__FIBONACCI_H_
#define FIBONACCI__FIBONACCI_H_

#include <vector>

/**
 * Dynamic programming:
 *  1- divide a problem to repetitive sub-problems
 *  2- remember the results of sub-problems to avoid resolving the repetitive sub-problems
 *
 * Dynamic programming to be approached in two ways:
 *  1- top-down approach:
 *    -it ends up with dividing and solving the problem recursively
 *
 *  2- bottom-up approach:
 *    - it ends up with dividing and solving the problem by looping through it
 *
 */

/**
 * solving Fibonacci series using dynamic programming approach (top-down)
 *
 * in this example only the problem is divided into sub problems recursively
 * we dont remember the repeated sub-problem results, which increase the time-complexity
 * time complexity = O(n*2^n) = O(2^n) = exponential
 *
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 *
 * return kth element in Fibonacci series
 */

int FibRec(int k)
{
  if(k <= 0)
    return 0;
  if(k == 1)
    return 1;

  return FibRec(k-1) + FibRec(k-2);
}

/**
 * divide the problem in to sub-problems and remember the results of repeated sub-problems recursively
 *
 * time complexity: O(n) = linear
 */

std::vector<int> mem(100, -1);

int FibRecWithMem(int k)
{
  if(mem[k] != -1)
    return mem[k];

  if(k <= 0)
    return 0;
  if(k == 1)
    return 1;

  mem[k] = FibRec(k-1) + FibRec(k-2);

  return mem[k];
}


/**
 * diving the problem into sub-problems and try to solve the very first sub-problem and
 * then the second sub-problem and then third ...
 *
 * time complexity = O(n)
 */

int FibLoop(int k)
{
  int pre = 0;
  int curr = 1;
  int sum;

  while (k > 0)
  {
    sum = curr + pre;
    pre = curr;
    curr = sum;
    --k;
  }

  return pre;
}

#endif//FIBONACCI__FIBONACCI_H_
