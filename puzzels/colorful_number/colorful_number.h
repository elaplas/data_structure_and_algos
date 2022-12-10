//
// Created by z639627 on 2/28/21.
//

#ifndef COLORFUL_NUMBER_COLORFUL_NUMBER_H_
#define COLORFUL_NUMBER_COLORFUL_NUMBER_H_

#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

class ColorfulNumber{

 public:


  bool isColorful(int number)
  {
    history_ = std::vector<int>();
    std::vector<int> digits = Number2Digits(number);
    std::vector<int> mask(digits.size(), 0);

   PowerSet(0, mask, digits);
    return result_;
  }

  void PowerSet(int index, std::vector<int> mask, const std::vector<int>& digits)
  {
    if(index>=digits.size())
    {
      mask[index]=0;
      int product = MultiplySet(mask, digits);
      if (std::find(history_.begin(), history_.end(), product) != history_.end())
      {
        result_=false;
        return;
      }
      else
      {
        if(product!=1)
          history_[product]=1;
      }
      PrintMask(mask);
      mask[index]=1;
      product = MultiplySet(mask, digits);
      if (std::find(history_.begin(), history_.end(), product) != history_.end())
      {
        result_=false;
        return;
      }
      else
      {
        if(product != 1)
          history_[product]=1;
      }
      PrintMask(mask);
      return;
    }

    mask[index] = 0;
    PowerSet(index+1, mask, digits);
    mask[index] = 1;
    PowerSet(index+1, mask, digits);

  }

  std::vector<int> Number2Digits(const int number)
  {
    int tmp =number;
    std::vector<int> digits;
    while (tmp)
    {
      int digit = tmp % 10;
      tmp /=10;
      digits.push_back(digit);
    }
    return digits;
  }

  int MultiplySet(std::vector<int> mask, std::vector<int> number)
  {
    int res =1;
    for (int i=0; i < number.size(); ++i)
    {
      if (mask[i])
      {
        res *= number[i];
      }
    }
    return res;
  }

  void PrintMask(const std::vector<int>& mask)
  {
    for (int i=0; i < mask.size(); ++i)
    {
      std::cout<<mask[i];
    }
    std::cout<<""<<std::endl;
  }

 private:
  std::vector<int> history_;
  bool result_{true};

};

#endif //COLORFUL_NUMBER__COLORFUL_NUMBER_H_
