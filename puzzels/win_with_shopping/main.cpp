#include <iostream>
#include <string>
#include <vector>

using namespace std;



/**
 *
 *  codeList  ["orange anything orange", "apple apple"]
 *  shopList  ["orange", "berry", "orange", "32", "apple", "apple"]
 *
 *  output --> true
 *
 *
 *  codeList  ["orange anything orange", "apple apple"]
 *  shopList  ["orange", "berry", "orange", "cocos", "apple"]
 *
 *  output --> false
 *
 *  Hint: If the order and items of shopList is the same as codeList the shopper is a winner
 *  Hint: "anything" can be anything
 *  Hint: numbers are ignored
 *
 */



bool DoesShopperWin(const vector<string>& codeList, const vector<string>& shopList)
{
  string codeStr;
  int wordCounter = 0;
  vector<bool> visited(codeList.size() + shopList.size(), false);
  for (int i=0; i < codeList.size(); ++i)
  {
    int start =0;
    int end =codeList[i].size();
    for (int j=0; j < codeList[i].size(); ++j)
    {
      if (codeList[i][j] == ' ')
      {
        end = j;
        if (codeList[i].substr(start, end) != "anything")
          codeStr = codeStr + codeList[i].substr(start, end);
        else
          visited[wordCounter] = true;
        start = end +1;
        ++wordCounter;
      }
    }
    if (codeList[i].substr(start, end) != "anything")
      codeStr = codeStr + codeList[i].substr(start, end);
    else
      visited[wordCounter] = true;
    ++wordCounter;
  }

  string shopStr;
  int shopCounter = 0;
  for (int i=0; i < shopList.size(); ++i)
  {
    bool isNumber = false;
    for (const auto s: shopList[i])
    {
      if ( s - '0' <= 9 && s - '0' >= 0)
      {
        isNumber = true;
        break;
      }
    }
    if (!isNumber)
    {
      if (!visited[shopCounter])
        shopStr= shopStr+shopStr[i] + " ";
      ++shopCounter;
    }
  }
  return shopStr == codeStr;
}



int main() {
  /// the winner shall be tested here
  return 0;
}
