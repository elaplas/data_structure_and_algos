
#include <iostream>
#include <vector>

/**
 * 
 * Calculating the integral of a 2D matrix involves creating a new matrix where each cell 
 * contains the sum of all the values in the original matrix that are above and to the left
 * of the cell. This operation is often used in image processing and computer vision algorithms.
 * 
 */


using namespace std;



vector<vector<int>> integralMatrixNaive(const vector<vector<int>>& A)
{
    vector<int> oneRow(A[0].size(), 0);
    vector<vector<int>> res(A.size(), oneRow);

    for (int i=0; i < A.size(); ++i)
    {
        for (int j=0; j < A[0].size(); ++j)
        {
            int ans = 0;
            for (int r =0; r <= i; ++r )
            {
                for (int c =0; c <= j; ++c)
                {
                    ans += A[r][c];
                }
            }
            res[i][j] = ans;
        }
    }

    return res;
}




vector<vector<int>> integralMatrix(const vector<vector<int>>& A)
{
    vector<int> oneRow(A[0].size()+1, 0);
    vector<vector<int>> lookup(A.size()+1, oneRow);

    vector<int> oneRow1(A[0].size(), 0);
    vector<vector<int>> res(A.size(), oneRow1);

    for (int i=1; i < A.size()+1; ++i)
    {
        for (int j=1; j < A[0].size()+1; ++j)
        {
            lookup[i][j] = lookup[i-1][j] + lookup[i][j-1] - lookup[i-1][j-1] + A[i-1][j-1]; 

            res[i-1][j-1] =  lookup[i][j];
        }
    }

    return res;
}


vector<vector<int>> integralMatrix(const vector<int>& A, int rowSize, int colSize)
{
    vector<int> oneRow(rowSize+1, 0);
    vector<vector<int>> lookup(colSize+1, oneRow);

    vector<int> oneRow1(rowSize, 0);
    vector<vector<int>> res(colSize, oneRow1);

    for (int i=1; i < rowSize+1; ++i)
    {
        for (int j=1; j < colSize+1; ++j)
        {
            int n = (i-1) * rowSize + j-1;
            lookup[i][j] = lookup[i-1][j] + lookup[i][j-1] - lookup[i-1][j-1] + A[n]; 
            res[i-1][j-1] = lookup[i][j];
        }
    }

    return res;
}


vector<int> integralMatrix1(const vector<int>& A, int rowSize, int colSize)
{
    vector<int> lookup((rowSize+1)*(colSize+1), 0);
    vector<int> res(A.size(), 0);
    
    for (int i=1; i < rowSize+1; ++i)
    {
        for (int j=1; j < colSize+1; ++j)
        {
            int h1 = (i-1)*(rowSize+1) + (j-1);
            int h2 = (i-1)*(rowSize+1) + j;
            int h3 = i*(rowSize+1) + (j-1);
            int h4 = i*(rowSize+1) + j;

            int m = (i-1)*(rowSize) + (j-1);

            lookup[h4] = lookup[h3] + lookup[h2] - lookup[h1] + A[m]; 
            res[m] = lookup[h4];
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

    auto res = integralMatrixNaive(A);
    cout<<"......naive.....\n";
    printMatrix(res);

    res = integralMatrix(A);
    cout<<"......optimized.....\n";
    printMatrix(res);

    vector<int> B={1,2,3,4,5,6,7,8,9};
    res = integralMatrix(B, 3, 3);
    cout<<"......optimized.....\n";
    printMatrix(res);

    auto res1 = integralMatrix1(B, 3, 3);
    cout<<"......optimized.....\n";
    for (auto el: res1)
    {
        cout<<el<<", ";
    }
    cout<<"\n";
}