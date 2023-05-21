#include <iostream>
#include <vector>
#include <algorithm>

/**
 * input: [3, 1, 4, 2, 5, 12, 15]
 * output: [2, 5, 12, 15] --> 4
 *
 *
 */


// Using two pointers
std::vector<int> longest_increasing_seq(const std::vector<int>& vec)
{
  int ptr_s = 0;
  int ptr = 0;
  int longest_seq = 0;
  int ptr_longest_s = 0;
  int ptr_longest_e = 0;
  
  while (ptr_s < vec.size()-1 && ptr < vec.size()-1)
  {
    if (vec[ptr+1] > vec[ptr])
    {
      ++ptr; 
    }
    else
    {
      ptr = ptr_s = ptr+1;
    }

    if (ptr - ptr_s > longest_seq)
    {
      longest_seq = ptr - ptr_s;
      ptr_longest_s = ptr_s;
      ptr_longest_e = ptr;
    }
  }

  std::vector<int> res {longest_seq+1, ptr_longest_s, ptr_longest_e};
  return res;
}


int main() {
  
  std::vector<int> vec{3, 1, 4, 2, 5, 12, 15};
  auto res = longest_increasing_seq(vec);
  for (auto el: res)
  {
    std::cout<<el<<"\n";
  }

  return 0;
}
