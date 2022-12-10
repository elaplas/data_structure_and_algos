#include <iostream>
#include <vector>
#include <vector>
#include <cstring>

using namespace std;


/**
 *   Rules:
 *   Every square has to contain a single number.
 *   Only the numbers from 1 through to 9 can be used.
 *   Each 3×3 box can only contain each number from 1 to 9 once.
 *   Each vertical column can only contain each number from 1 to 9 once.
 */

/// time complexity: O(n^2) or o(n^4) and accessing "board" more than one time!
/// space complexity: s(n)

int validSudoku(const vector<string>& board)
{
  bool rowHistory[10];
  bool colHistory[10];
  bool boxHistory[10];

  for (int i=0; i < board.size(); ++i)
  {
    for (int j=0; j < board.size(); ++j)
    {
      memset(rowHistory, false, 10);
      memset(colHistory, false, 10);
      if (board[i][j] - '0' != '.')
      {
        if (rowHistory[board[i][j]-'0'])
          return 0;
        else
          rowHistory[board[i][j]-'0'] = true;
      }

      if (board[j][i] - '0' != '.')
      {
        if (colHistory[board[j][i]-'0'])
          return 0;
        else
          colHistory[board[j][i]-'0'] = true;
      }

      if (i%3 ==0 && j%3==0 && i != board.size()-1 && j != board.size()-1)
      {
        memset(boxHistory, false, 10);
        for (int l=0; l <3; ++l)
        {
          for (int k=0; k < 3; ++k)
          {
            if (board[i+l][j+k] - '0' != '0')
            {
              if (boxHistory[board[i+l][j+k] - '0'])
                return 0;
              else
                boxHistory[board[i+l][j+k] - '0'] = true;
            }
          }
        }
      }

    }
  }

}

/// time complexity: O(n^2) and accessing "board" only one time!
/// space complexity: o(n^3)
int validSudokuOptimized(const vector<string>& board ) {
  bool rowHistory[9][10];
  bool colHistory[9][10];
  bool boxHistory[3][3][10];
  memset(rowHistory, false, 10);
  memset(colHistory, false, 10);
  memset(boxHistory, false, 10);

  for (int i = 0; i < board.size(); ++i)
  {
    for (int j = 0; j < board.size(); ++j)
    {
      if (board[i][j] == '.')
      {
        continue;
      }

      int number = board[i][j] - '0';

      if (rowHistory[i][number])
        return 0;
      else
        rowHistory[i][number] = true;

      if (colHistory[j][number])
        return 0;
      else
        colHistory[j][number] = true;

      if(boxHistory[i/3][j/3][number])
        return 0;
      else
        boxHistory[i/3][j/3][number] = true;
    }
  }

  return 1;

}


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
