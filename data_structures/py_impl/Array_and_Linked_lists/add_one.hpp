
#include <iostream>
#include <deque>

using namespace std;



deque<int> addOne(const deque<int>& arr, int i)
{
    if (i == arr.size()-1)
    {
        deque<int> res;
        if(arr[i] == 9)
        {
            res.push_back(1);
            res.push_back(0);
        }
        else
        {
            res.push_back(arr[i]+1);
        }

        return res;
    }

    auto res = addOne(arr, i+1);
    auto front = res.front();

    if (front == 1)
    {
        if (arr[i] == 9)
        {
            res.push_back(0);
        }
        else
        {
            res[i] = arr[i]+1;
        }
    }
    else
    {
        res.push_front(arr[i]);
    }

    return res;
}

deque<int> addOne(const deque<int>& arr)
{
    return addOne(arr, 0);
}


int main()
{

    deque<int> data{3,9,9,9};
    auto res = addOne(data);

    for (auto el: res)
    {
        cout<<el<<"\n";
    }
   
    return 0;
}