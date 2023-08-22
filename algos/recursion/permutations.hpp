
#include <iostream>
#include <vector>


using namespace std;


vector<vector<int>> gen_permutations(vector<int>& vec, int n)
{
    if (n == vec.size()-1)
    {
        vector<vector<int>> res;
        res.push_back(vector<int>()={vec[vec.size()-1]});
        return res;
    }

    auto res_t = gen_permutations(vec, n+1);

    vector<vector<int>> res_t_1;
    for (auto& res_t_i: res_t)
    {
        for (int i=0; i <= res_t_i.size(); ++i)
        {
            auto tmp = res_t_i;
            tmp.insert(tmp.begin()+i, vec[n]);
            res_t_1.push_back(tmp);
        }
    }

    return res_t_1;
}



int main()
{
    vector<int> vec = {1,2,3};
    auto res = gen_permutations(vec, 0);
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