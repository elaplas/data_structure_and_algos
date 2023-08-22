#include <vector>
#include <iostream>


using namespace std;


int lcs(string& A, string& B, int i, int j)
{
    if (i >= A.size() || j > B.size())
    {
        return 0;
    }

    if (A[i] == B[j])
    {
        return 1 + lcs(A, B, i+1, j+1);
    }
    else
    {
        return max(lcs(A,B, i+1, j), lcs(A,B, i, j+1));
    }
}


int lcs_DP(string& A, string& B)
{
    int cols = A.size() +1;
    int rows = B.size() + 1;
    vector<int> oneRow(cols, 0);
    vector<vector<int>> lookup(rows, oneRow);
    for (int i = rows-2; i >= 0; --i)
    {
        for (int j = cols-2; j >=0; --j)
        { 
            if (A[j] == B[i])
            {
                lookup[i][j] = 1 + lookup[i+1][j+1];
            }
            else
            {
                lookup[i][j] = max(lookup[i+1][j], lookup[i][j+1]);
            }
        }
    }

    return lookup[0][0];  
}



int main()
{
    string A("ABCD");
    string B("AXBXDX");

    auto res = lcs(A, B, 0, 0);
    cout<<res<<"\n";

    res = lcs_DP(A, B);
    cout<<res<<"\n";
 
    return 0;
}