#include <iostream>
#include <vector>



using namespace std;



void quickSort(vector<int>& vec, int s, int e)
{
    if ( s >= e)
    {
        return;
    }

    int p = e;
    int ptr = s;

    while (ptr < p)
    {
        if (vec[ptr] > vec[p])
        {
            if (p-ptr > 1)
            {
                auto tmp = vec[p-1];
                vec[p-1] = vec[p];
                vec[p] = vec[ptr];
                vec[ptr] = tmp;
                --p;
            }
            else
            {
                auto tmp = vec[p];
                vec[p] = vec[ptr];
                vec[ptr] = tmp;
                --p;
            }
        }
        else
        {
            ++ptr;
        }
    }

    quickSort(vec, s, p-1);
    quickSort(vec, p+1, e);
}


int main()
{
    vector<int> vec = {2,5,6,1,3, 10, 7};
    quickSort(vec, 0, vec.size()-1);

    for (auto el: vec)
    {
        cout<<el<<"\n";
    }
   
    return 0;
}