
#include <iostream>
#include "range.h"


int main()
{
   range<2, 10> range_a;

   // In range-based loop, one iterator is constructed and kept in the brackets and another iterator is constructed and assigned with the copy of the iterator
   // in the brackets and kept in the curly brackets
   for (auto r: range<2, 10>())
   {
      std::cout<<r<<std::endl;
   }

   std::cout<<"..............."<<std::endl;

   for (auto r: range<10, 20>())
   {
      std::cout<<r<<std::endl;
   }

   // In for-loop, one iterator is constructed and kept in the brackets and at each iteration, another iterator is constructed and assigned with
   // the copy of the iterator in the brackets and kept in the curly brackets
   std::cout<<"..............."<<std::endl;

   auto endIt = range_a.end();
   for (auto it = range_a.begin(); it != endIt; it++)
   {
      std::cout<<*it<<std::endl; 
   }

   // Knowing the range-based loop and for-loop mechanisms help us implement iterators specially operator++ correctly

   return 0;
}