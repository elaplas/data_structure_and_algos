#include <iostream>
#include <utility>
#include <type_traits>

#include "some_characteristics.h"
#include "remove_reference.h"
#include "forwarding.h"


using namespace Example;

// For perfect forwarding (passing rvalue reference as revalue reference), we combine universal reference(T&&) with "forward"

template<class T>
void func(T&&){};


template<class T>
void wrapper(T&& t)
{
    func(forward<int>(t));
}

int main()
{
    // Some characteristics
    std::cout<<".................. Some characteristics.............."<<std::endl;
    func_a(100);
    func_b(100);
    is_same<ConstInt, ConstConstInt, 1>();
    is_same<ConstInt, ConstConstConstInt, 2>();
    is_same<intRef, intRefRef, 3>();
    is_same<intRef, intRefRefRef, 4>();
    is_same<intRef, intRefRValRef, 5>();
    // Removing Reference
    std::cout<<".................. Removing Reference .............."<<std::endl;
    is_same<int, remove_reference<int>::type, 6>();
    is_same<int, remove_reference<int&>::type, 7>();
    is_same<int, remove_reference<int&&>::type, 8>();
    // Forwarding
    std::cout<<".................. Forwarding .............."<<std::endl;
    int x = 10; 
    is_same<int&&, decltype(forward<int>(x)), 9>();
    is_same<int&, decltype(forward<int&>(x)), 10>();
    is_same<int&&, decltype(forward<int>(100)), 11>();
    is_same<int&, decltype(forward<int&>(100)), 12>();
    std::cout<<".................. Perfect forwarding .............."<<std::endl;
    // Perfect forwarding
    wrapper(200); // 200 is rvalue and stays as rvalue reference 
    int y = 200;
    wrapper(y);  // y is passed as lvalue reference and stays lvalue reference. Hint: implicit specialization:  wrapper(y) = wrapper<int&>(y)
}