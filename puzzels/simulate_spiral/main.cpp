#include <iostream>
#include <vector>


std::vector<std::vector<int>> SimulateSpiral(int size)
{
  std::vector<int> row(size+1, 0);
  std::vector<std::vector<int>> A(size+1, row);


  int r,c;
  r=c=0;
  int counter=0;
  int dir =0;
  while (counter < size * size)
  {
      /// go right
      A[r][c] = ++counter;
      if(dir == 0)
      {
        ++c;
        if(A[r][c] != 0 || c==size)
        {
          dir=1;
          --c;
          ++r;
        }
      }
      /// go down
      else if(dir ==1)
      {
        ++r;
        if(A[r][c] != 0 || r==size)
        {
          dir=2;
          --r;
          --c;
        }
      }
      /// go left
      else if(dir ==2)
      {
       --c;
        if(A[r][c] != 0 || c==-1)
        {
          dir=3;
          --r;
          ++c;
        }
      }
      /// go up
      else if(dir ==3)
      {
        --r;
        if(A[r][c] != 0 || r==size)
        {
          dir=0;
          ++r;
          ++c;
        }
      }
  }
  return A;
}

void PrintMatrix(const std::vector<std::vector<int>>& A)
{
  for(int r=0; r < A.size(); ++r)
  {
    for (int c=0; c < A.size(); ++c )
    {
      std::cout<<A[r][c]<<", ";
    }
    std::cout<<"\n";
  }

}

int main() {


  auto A = SimulateSpiral(3);
  PrintMatrix(A);
  return 0;
}
