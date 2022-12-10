#include <iostream>
#include <vector>


void TransposeMatrix(std::vector<std::vector<int>>& A)
{
  for(int r=0; r < A.size(); ++r)
  {
    for (int c=0; c < A.size(); ++c )
    {
      if ( r != c && r<c)
      {
        int tmp=A[c][r];
        A[c][r]=A[r][c];
        A[r][c]=tmp;
      }
    }
  }
}

void ExchangeCols(std::vector<std::vector<int>>& A)
{
  for(int r=0; r < A.size(); ++r)
  {
    for (int c=0; c < A.size()/2; ++c)
    {
      int tmp = A[r][(A.size()-1)-c];
      A[r][(A.size()-1)-c] = A[r][c];
      A[r][c] = tmp;
    }
  }
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

void RotateMatrix(std::vector<std::vector<int>>& A )
{
  TransposeMatrix(A);
  ExchangeCols(A);
}


int main() {

  std::vector<std::vector<int>> A{{1,2},{3,4}};
  PrintMatrix(A);
  std::cout<<"................."<<std::endl;
  RotateMatrix(A);
  PrintMatrix(A);

  return 0;
}
