
#include <iostream>
#include "range.h"


int main()
{
   range<2, 10> range_a;

   for (auto r: range<2, 10>())
   {
      std::cout<<r<<std::endl;
   }

   std::cout<<"............"<<std::endl;

   for (auto r: range<10, 20>())
   {
      std::cout<<r<<std::endl;
   }

   return 0;
}