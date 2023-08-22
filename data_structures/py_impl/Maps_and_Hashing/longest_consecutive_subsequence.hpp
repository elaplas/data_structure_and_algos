
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> lcs(const vector<int>& vec) 
{
    unordered_map<int, bool> map;
    int max_len = 0;
    int start_el = -1;

    for (auto el: vec)
    {
        int cur_el = el;
        int cur_len = 0;
        int cur_start_el = el;

        while (map.find(cur_el+1) != map.end())
        {
            ++cur_len;
            cur_el = cur_el+1;
        }

        cur_el = el;

        while (map.find(cur_el-1) != map.end())
        {
            ++cur_len;
            cur_el = cur_el-1;
            --start_el; 
        }

        map[el] = true;

        if (cur_len > max_len)
        {
            start_el = cur_start_el;
            max_len = cur_len;
        }
    }

    vector<int> res;
    for (int i= start_el; i <= max_len; ++i)
    {
        res.push_back(i);
    }

    return res;
}


vector<int> lcs_1(vector<int>& vec)
{
    sort(vec.begin(), vec.end());

    int g_start=0;
    int g_end=0;

    int start = 0;
    int end = 1;
    int cur_len=0;

    while (end < vec.size()){

        if (vec[end]-vec[end-1] > 1)
        {
            start = end;
        }

        if (end-start > g_end -g_start)
        {
            g_start = start;
            g_end = end;
        }

        ++end;
    }

    vector<int> res;
    for (int i= vec[g_start]; i <= vec[g_start]+g_end; ++i)
    {
        res.push_back(i);
    }

    return res;
}


int main()
{
    vector<int> vec = {5, 4, 7, 10, 1, 3, 55, 2};

    auto res = lcs_1(vec);
    for(auto el: res)
    {
        cout<<el<<"\n";
    }
 
   
    return 0;
}