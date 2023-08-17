
#include <iostream>
#include <vector>

using namespace std;

// There is bug in this implementation


int max_sub_array_helper(const vector<int>& arr, int s, int e, string side) 
{
    if (s==e)
    {
        return arr[s];
    }

    int m = (s+e)/2;
    auto L = max_sub_array_helper(arr, s, m, "left");
    auto R = max_sub_array_helper(arr, m+1, e, "right");

    if (side == "left")
    {
        return max(R, L+R);
    }

    if (side == "right")
    {
        return max(L, L+R);
    }
}

int max_sub_array(const vector<int>& arr)
{
    int m = (arr.size() -1)/2;

    auto L = max_sub_array_helper(arr, 0, m, "left");
    auto R = max_sub_array_helper(arr, m+1, arr.size()-1, "right");

    return max(max(R, L), R+L);
}



int main()
{
    vector<int> arr={1,2,3,-4,6};
    auto res = max_sub_array(arr);
    cout<<res<<"\n";

    vector<int> arr1={1,2,-5, -4, 1, 6};
    auto res1 = max_sub_array(arr1);
    cout<<res1<<"\n";

    vector<int> arr2={-12, 15, -13, 14, -1, 2, 1, -5, 4};
    auto res2 = max_sub_array(arr2);
    cout<<res2<<"\n";
    
   
    return 0;
}