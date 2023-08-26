#include <vector>
#include <iostream>


using namespace std;


vector<vector<int>> matrix_dx(const vector<vector<int>>& M, const vector<vector<int>>& kernel)
{
    vector<int> oneRow(M[0].size(), 0);
    vector<vector<int>> res(M.size(), oneRow);

    for(int r=0; r <= M.size()-kernel.size(); ++r)
    {
        for(int c=0; c <= M[0].size()-kernel[0].size(); ++c)
        {
            int ans = 0;
            for (int n=r; n < r+kernel.size(); ++n)
            {
                for (int m=c; m < c+kernel.size(); ++m)
                {
                    ans += (M[n][m] * kernel[n-r][m-c]);
                }
            }
            res[r+(kernel.size()/2)][c + (kernel[0].size()/2)] = ans;
        }
    }

    return res;
}





void printMatrix(vector<vector<int>> A)
{
    for (int r =0; r < A.size(); ++r )
    {
        for (int c =0; c < A[0].size(); ++c)
        {
            cout<<A[r][c]<<", ";
        }
        cout<<"\n......\n";
    }
}

int main()
{
    vector<int> row1={1,2,3};
    vector<int> row2={4,5,6};
    vector<int> row3={7,8,9};
    vector<vector<int>> A;
    A.push_back(row1);
    A.push_back(row2);
    A.push_back(row3);

    cout<<".....dx......\n";
    vector<int> kernel1 = {-1, 0, 1};
    vector<int> kernel2 = {-2, 0, 2};
    vector<int> kernel3 = {-1, 0, 1};
    vector<vector<int>> kernel;
    kernel.push_back(kernel1);
    kernel.push_back(kernel2);
    kernel.push_back(kernel3);

    auto res = matrix_dx(A, kernel);
    printMatrix(res);
    
    return 0;
}