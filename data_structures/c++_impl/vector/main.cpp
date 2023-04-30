#include <iostream>
#include "vector.h"


using namespace P;



int main() {

  Vector<int> vec;

    for (int i=0; i <9; ++i)
    {
        vec.push_back(i);
    }

    vec.emplace_back(9);

    std::cout<<"..................................."<<std::endl;
    for (auto& el: vec)
    {
        std::cout<<el<<std::endl;
    }

    auto it = vec.begin();
    vec.erase(it+3, it+7);

    std::cout<<"..................................."<<std::endl;
    for (auto& el: vec)
    {
        std::cout<<el<<std::endl;
    }

    std::cout<<"..................................."<<std::endl;
    vec.erase(it+2);
    for (auto& el: vec)
    {
        std::cout<<el<<std::endl;
    }


  return 0;
}
