#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

int findMaxContiguousSubArray(const std::vector<int>& vec)
{

  int local_max = 0;
  int global_max = -1001;

for (int i=0; i <vec.size(); ++i)
  {
    local_max = std::max(local_max + vec[i], vec[i]);

    if (local_max > global_max)
    {
      global_max = local_max;
    }

    if (vec[i] < 0)
    {
      local_max = vec[i];
    }
  }
}


void RotateMatrixBy90(std::vector<std::vector<int>>& A)
{

  for(int i=0; i<A.size(); ++i)
  {
    /// transpose it
    for (int j=0; j < A.size(); ++j)
    {
      if (i < j)
      {
        std::swap(A[i][j], A[j][i]);
      }
    }
    /// swap columns
    for (int j=0; j < A.size()/2; ++j)
    {
      std::swap(A[i][j], A[i][A.size()-j-1]);
    }
    }
}

struct Interval{
  int start;
  int end;
  Interval(int s, int e): start(s), end(e){}
};

std::vector<Interval> MergeOverlappingIntervals(std::vector<Interval>& vecIntervals)
{
  int start = vecIntervals[0].start;
  int end = vecIntervals[0].end;

  std::sort(vecIntervals.begin(), vecIntervals.end(), [](const Interval& i1, const Interval& i2){
    return i1.start < i2.start;
  });

  std::vector<Interval> mergedIntervals;
  for (int i=1; i < vecIntervals.size(); ++i)
  {
    if (vecIntervals[i].start < end)
    {
      if(vecIntervals[i].end > end)
      {
        end = vecIntervals[i].end;
      }
    }
    else
    {
      mergedIntervals.push_back(Interval(start, end));
      start = vecIntervals[i].start;
      end = vecIntervals[i].end;
    }

    /// take care of last item
    if (i == vecIntervals.size()-1)
    {
      mergedIntervals.push_back(Interval(start, end));
    }
  }
  return mergedIntervals;
}


int FindDuplicateInArray(const std::vector<int>& vec)
{
  bool history[vec.size()+1];
  std::memset(history, false, vec.size()+1);
  int res = -1;
  for (int i =0; i < vec.size(); ++i)
  {
    if (history[i])
    {
      res = history[i];
    }
    else
    {
      history[i] = true;
    }
  }
  return res;
}

std::vector<int> WaveArray(const std::vector<int> vec)
{
  std::sort(vec.begin(), vec.end(), [](int a, int b){
    return a <b;
  });

  for (int i=0; i < vec.size()-1; ++i)
  {
    if (i%2 == 0)
    {
      std::swap(vec[i], vec[i+1]);
    }
  }
}


int FindMaxDistance(const std::vector<int> vec)
{
  std::vector<std::pair<int, int>> vecPairs;
  for (int i =0; i< vec.size(); ++i)
  {
    vecPairs.push_back(std::pair<int,int>(vec[i], i));
  }

  std::sort(vec.begin(), vec.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b){
    return a.first < b.first;
  });


  int maxDis = 0;
  int maxIndex = vec.size()-1;
  for (int i = vec.size()-2 ; i >= 0; --i)
  {
    maxDis = std::max(maxDis,  vecPairs[maxIndex].second - vecPairs[i].second);
    maxIndex = std::max(maxIndex, vecPairs[i].second);
  }
  return maxDis;
}

int SquareRootOfInteger(int x)
{
  int start = 1;
  int end = x-1;
  int mid = (x/2) ;

  while (start != end)
  {
    if (mid*mid > x)
    {
      end = mid;
    }
    else
    {
      start = mid;
    }
    mid = ( start + end ) / 2;
  }
  return start;
}

int SearchInRotatedSortedArray(const std::vector<int> vec, int b)
{
  int start = 0;
  int end = vec.size() -1;
  int mid = (start + end)/2;

  while (start < end)
  {

    if (vec[mid] == b)
      return mid;

    if ( vec[start] < vec[mid] )
    {
      if (b <= vec[mid] && b >= vec[start])
      {
        end = mid;
      }
      else
      {
       ++mid;
      }
    }

    if (vec[end] > vec[mid])
    {
      if(b <= vec[end] && b >= vec[mid])
      {
        start = mid;
      }
      else
      {
        --mid;
      }
    }
    mid = (start + end)/2;
  }
}

/// is str1 in str2?
bool IsStrInStr(const char* str1, const char* str2)
{
  int sizeStr1 = std::strlen(str1)+1;
  int sizeStr2 = std::strlen(str2)+1;
  bool res = false;
  int counter = 0;
  for (int i =0; i< sizeStr2; ++i)
  {
    if (*(str2+i) == *str1 )
    {
      for (int j=0; j< sizeStr1; ++j)
      {
        if (i+j < sizeStr2) /// not exceed the size of str2
        {
          if (*(str1 + j) == *(str2+i+j))
          {
            ++counter;
          }
        }
      }
      if (counter == sizeStr1)
      {
        res = true;
        break;
      }
    }
  }
  return res;
}

std::string ReverseString(const std::string str)
{
  std::string reversedString;
  int start;
  int end = str.size();

  for (int i = str.size(); i > 0 ; --i )
  {
    if (str[i-1] != ' ' && str[i] == ' ')
    {
      start = i-1;
      reversedString += str.substr(start, end);
      reversedString += " ";
    }

    if (str[i-1] == ' ' && str[i] != ' ')
    {
      end = str[i];
    }
  }
}


int StringToInteger(const std::string& str )
{
  int integer = 0;
  int sign = 1;
  for (int i=0; i< str.size(); ++i)
  {
    if (str[i] == '-')
    {
      sign *= -1;
      continue;
    }
    int dig = str[i] - '0';
    if(dig <= 9 && dig>=0)
    {
      integer *= 10;
      integer += dig;
    }
  }
  return integer * sign;
}

int InverseBits(int x)
{
  int numBits=0;
  int tmpX = x;
  while(tmpX != 0)
  {
    tmpX /= 2;
    ++numBits;
  }
  int reversed = x << (32 - numBits );
  return reversed;
}

///array is sorted
void RemoveDuplicatesInPlace(std::vector<int>& vec)
{
  int j=0;
  for (int i=0; i< vec.size()-1; ++i)
  {
    if(vec[i] != vec[i+1])
    {
      vec[j] = vec[i];
      ++j;
    }

    if (i == vec.size()-2)
    {
      vec[j]=vec[i+1];
    }
  }
  vec.erase(vec.begin() + j+1, vec.end() );
}

/// evaluate the expression: ["2", "1", "+", "3", "*"] --> ( 2 + 1 ) * 3
int EvaluateExpression(const std::vector<std::string>& vec)
{
  std::stack<int> s;

  for (int i=0; i < vec.size(); ++i)
  {

    if (vec[i] != "*" && vec[i] != "+" && vec[i] != "-" && vec[i] != "/")
    {
      int num = std::stoi(vec[i]);
      s.push(num);
    }
    else
    {
      int operand1 = s.top();
      s.pop();
      int operand2 = s.top();
      s.pop();
      if(vec[i] == "*" )
      {
        s.push(operand1 * operand2);
      }
      else if (vec[i] == "+" )
      {
        s.push(operand1 + operand2);
      }
      else if (vec[i] == "-" )
      {
        s.push(operand1 - operand2);
      }
      else
      {
        s.push(operand1 / operand2);
      }
    }
  }

  return s.top();
}

std::vector<int> MaxOfSlidingWindow(const std::vector<int>& vec, int window)
{
  std::deque<int> deque1;
  int startWin = 0;
  std::vector<int> maxes;

  for (int i=0; i<vec.size(); ++i)
  {
    if (deque1.empty())
      deque1.push_back(i);

    if (vec[i] >  vec[deque1.front()])
    {
      while (vec[i] > vec[deque1.back()])
      {
        deque1.pop_back();
      }
      deque1.push_back(i);
    }
    else
    {
      deque1.push_back(i);
    }

    if ( i > window-1)
    {
      ++startWin;
      maxes.push_back(vec[deque1.front()]);
    }

    if (deque1.front() < startWin )
      deque1.pop_front();
  }
}



int main() {
  /// how to initialize vector of vectors
  std::vector<int> vec(10, 0);
  std::vector<std::vector<int>> vec1(10, vec);

  return 0;
}
