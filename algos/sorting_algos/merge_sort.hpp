#include <iostream>
#include <vector>

using namespace std;


vector<int> mergeSort(const vector<int>& vec, int s, int e)
{
    if ( s == e)
    {
        return vector<int>() = {vec[s]};
    }

    int m = (s+e)/2;

    auto L = mergeSort(vec, s, m);
    auto R = mergeSort(vec, m+1, e);

    vector<int> res;

    int ptr_l = 0;
    int ptr_r = 0;

    while (ptr_l < L.size() && ptr_r < R.size())
    {
        if (L[ptr_l] < R[ptr_r])
        {
            res.push_back(L[ptr_l]);
            ++ptr_l;
        }
        else
        {
            res.push_back(R[ptr_r]);
            ++ptr_r;
        }
    }

    for (int i = ptr_l; i < L.size(); ++i)
    {
        res.push_back(L[i]);
    }

    for (int i = ptr_r; i < R.size(); ++i)
    {
        res.push_back(R[i]);
    }

    return res;
}


int main()
{
    vector<int> vec = {2,5,6,1,3,10,7};
    auto res = mergeSort(vec, 0, vec.size()-1);

    for (auto el: res)
    {
        cout<<el<<"\n";
    }
   
    return 0;
}