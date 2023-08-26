#include <vector>
#include <iostream>


using namespace std;



vector<vector<int>> matrix_dx(const vector<vector<int>>& M, const vector<int>& kernel)
{
    vector<int> oneRow(M[0].size(), 0);
    vector<vector<int>> res(M.size(), oneRow);

    for(int r=0; r < M[0].size(); ++r)
    {
        for(int c=0; c <= M.size()-kernel.size(); ++c)
        {
            int ans = 0;
            for(int n = c; n < c + kernel.size(); ++n)
            {
                ans += (M[r][n] * kernel[n-c]);
            }
            res[r][c+(kernel.size()/2)] = ans;
        }
    }

    return res;
}


vector<vector<int>> matrix_dy(const vector<vector<int>>& M, const vector<int>& kernel)
{
    vector<int> oneRow(M[0].size(), 0);
    vector<vector<int>> res(M.size(), oneRow);

    for(int c=0; c < M[0].size(); ++c)
    {
        for(int r=0; r <= M.size()-kernel.size(); ++r)
        {
            int ans = 0;
            int offset = r;
            for (int n = r; n < r+kernel.size(); ++n)
            {
                ans += M[n][c] * kernel[n-r];
            }
            res[r + kernel.size()/2][c] = ans;
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
    vector<int> kernel = {-1, 0, 1};
    auto res = matrix_dx(A, kernel);
    printMatrix(res);
    cout<<".....dy......\n";
    res = matrix_dy(A, kernel);
    printMatrix(res);
}