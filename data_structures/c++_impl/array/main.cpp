#include <iostream>
#include "array.h"


using namespace std;

int main() {

    Array<int, 10> arr;

    cout<<"...................\n";
    cout<<arr.size()<<"\n";
    cout<<arr.max_size()<<"\n";
    
    for (int i=0; i < 10; ++i)
    {
        arr.emplace_back(i);
    }

    cout<<"...................\n";
    cout<<arr.size()<<"\n";
    cout<<arr.max_size()<<"\n";

    cout<<"...................\n";
    for (auto el: arr)
    {
        cout<<el<<"\n";
    }

    for (int i=0; i < 5; ++i)
    {
        arr.pop_front();
    }

    cout<<"...................\n";
    cout<<arr.front()<<"\n";
    cout<<arr.back()<<"\n";

    cout<<"...................\n";
    for (auto el: arr)
    {
        cout<<el<<"\n";
    }


  return 0;
}
