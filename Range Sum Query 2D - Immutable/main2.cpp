#include <bits/stdc++.h>
using namespace std;

    class NumMatrix
    {
        int m;
        int n;
        vector<vector<int>> dp;

    public:
        NumMatrix(vector<vector<int>> &matrix)
        {
            m = matrix.size();
            n = matrix[0].size();
            dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
                }
            }
        }

        int sumRegion(int row1, int col1, int row2, int col2)
        {
            int sum = dp[row2 + 1][col2 + 1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];

            return sum;
        }
    };

int main(){
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1}, 
        {1, 2, 0, 1, 5}, 
        {4, 1, 0, 1, 7}, 
        {1, 0, 3, 0, 5}
    };
    NumMatrix nm = NumMatrix(matrix);
    cout << nm.sumRegion(2,1,4,3) << endl;
    cout << nm.sumRegion(1,1,2,2) << endl;
    cout << nm.sumRegion(1,2,2,4) << endl;
    cout << nm.sumRegion(0,0,0,0) << endl;
}