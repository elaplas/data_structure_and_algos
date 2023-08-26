
#include <vector>
#include <iostream>


using namespace std;
/**
 * Calculating the derivative of a 2D matrix involves computing the differences 
 * between adjacent elements along rows and columns. This is often used in image
 * processing and edge detection algorithms to highlight boundaries and changes in intensity.
 * 
 */

vector<vector<int>> matrix_dx(const vector<vector<int>>& M)
{
    vector<int> oneRow(M[0].size(), 0);
    vector<vector<int>> res(M.size(), oneRow);

    for(int r=0; r < M[0].size(); ++r)
    {
        for(int c=1; c < M.size(); ++c)
        {
            res[r][c] = M[r][c] - M[r][c-1];
        }
    }

    return res;
}


vector<vector<int>> matrix_dy(const vector<vector<int>>& M)
{
    vector<int> oneRow(M[0].size(), 0);
    vector<vector<int>> res(M.size(), oneRow);

    for(int r=1; r < M[0].size(); ++r)
    {
        for(int c=0; c < M.size(); ++c)
        {
            res[r][c] = M[r][c] - M[r-1][c];
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
    auto res = matrix_dx(A);
    printMatrix(res);
    cout<<".....dy......\n";
    res = matrix_dy(A);
    printMatrix(res);

}