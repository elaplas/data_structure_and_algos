
#include <iostream>
#include <vector>


using namespace std;


vector<vector<int>> k_permutations(vector<int>& vec, int i, int k)
{
    if (i == k)
    {
        vector<vector<int>> res;
        for (auto el: vec)
        {
            res.push_back(vector<int>()={el});
        }

        return res;
    }

    auto res_t = k_permutations(vec, i+1, k);

    vector<vector<int>> res_t_1;
    for (auto& res_t_i: res_t)
    {
        for (auto el: vec){

            if (find(res_t_i.begin(), res_t_i.end(), el) == res_t_i.end())
            {
                auto tmp = res_t_i;
                tmp.push_back(el);
                res_t_1.push_back(tmp);
            }
        }
    }

    return res_t_1;
}



int main()
{
    vector<int> vec = {1,2,3};
    auto res = k_permutations(vec, 1, 2);
    for (auto& per: res)
    {
        cout<<"......\n";
        for(auto el: per)
        {
            cout<<el<<"\n";
        }
        cout<<"......\n";
    }
    return 0;
}