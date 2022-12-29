#include <iostream>
#include "vector.h"


using namespace P;


struct A{

    int m_i;
    float m_j;

    A():A(0, 0.f){}
    A(int i):m_i(i), m_j(0.f){}
    A(int i, float j):m_i(i), m_j(j){}
};


int main() {

  Vector<int> vector1;

  for (int i = 0; i < 25; ++i)
  {
    vector1.push_back(i);
  }

  for (int i = 0; i < 25; ++i)
  {
    std::cout<< vector1[i]<< "\n";
  }

  std::cout<<"............................................"<<std::endl;

  for (auto it = vector1.begin(); it != vector1.end(); it++)
  {
    std::cout<< *it << "\n";
  }

  std::cout<<"............................................"<<std::endl;

  vector1.erase(vector1.begin() + 5, vector1.begin()+10);

   for (auto it = vector1.begin(); it != vector1.end(); it++)
  {
    std::cout<< *it << "\n";
  }
  
  std::cout<<"............................................"<<std::endl;

  vector1.erase(vector1.begin() + 15);

  for (auto it = vector1.begin(); it != vector1.end(); it++)
  {
    std::cout<< *it << "\n";
  }

  std::cout<<"........................emplace_back...................."<<std::endl;

  Vector<A> vector2;
  vector2.emplace_back(25);         // It constructs struct "A" in place without copying by calling the constructor with one argument  
  vector2.emplace_back(30, 2.5);    // It constructs struct "A" in place without copying by calling the constructor with two arguments  
  vector2.emplace_back(A(45, 3.5)); // It constructs struct "A" in place without copying by calling the default assignment constructor
  vector2.push_back(A(55, 4.5));    // It copies the passed rvalue into the back of vector using copy operator (T operator=(const T& other){})


  std::cout<<vector2[0].m_i<<std::endl;
  std::cout<<vector2[0].m_j<<std::endl;
  std::cout<<vector2[1].m_i<<std::endl;
  std::cout<<vector2[1].m_j<<std::endl;
  std::cout<<vector2[2].m_i<<std::endl;
  std::cout<<vector2[2].m_j<<std::endl;
  std::cout<<vector2[3].m_i<<std::endl;
  std::cout<<vector2[3].m_j<<std::endl;


  return 0;
}
