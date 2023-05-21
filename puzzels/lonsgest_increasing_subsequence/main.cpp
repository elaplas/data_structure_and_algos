#include <iostream>
#include <vector>
#include <algorithm>

/**
 * input: [3, 1, 4, 2, 5, 12, 15]
 * output: [1, 2, 5, 12, 15] --> 5
 *
 *
 */


/* idea:
 * this problem can be reduced to a longest common subsequence if a new array from the given one
 * is generated and sorted. The longest increasing subsequence is the longest common subsequence b/w two arrays
*/

int longest_increasing_seq_helper(
  const std::vector<int>& vec_x,
  int i, 
  const std::vector<int>& vec_y, 
  int j)
{
  if (i >= vec_x.size() || j >= vec_y.size())
  {
    return 0;
  }

  if (vec_x[i] == vec_y[j])
  {
    return 1 + longest_increasing_seq_helper(vec_x, i+1, vec_y, j+1);
  }
  else
  {
    return std::max(longest_increasing_seq_helper(vec_x, i+1, vec_y, j), 
    longest_increasing_seq_helper(vec_x, i, vec_y, j+1));
  }
}

int longest_increasing_seq(const std::vector<int>& vec)
{
  std::vector<int> sorted_vec(vec);
  std::sort(sorted_vec.begin(), sorted_vec.end());
  return longest_increasing_seq_helper(sorted_vec, 0, vec, 0);
}


int main() {
  
  std::vector<int> vec{3, 1, 4, 2, 5, 12, 15};
  auto res1 = longest_increasing_seq(vec);
  std::cout<<res1<<"\n";

  return 0;
}
