/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int implementation2d(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
    int implementation1st(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(3, 0)));
        int ans = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j][0] = 1 + (i + 1 < m ? dp[i + 1][j][0] : 0);
                    dp[i][j][1] = 1 + (j + 1 < n ? dp[i][j + 1][1] : 0);
                    int size = min(dp[i][j][0], dp[i][j][1]);
                    int derived = i + 1 < m && j + 1 < n ? dp[i + 1][j + 1][2] : 0;
                    dp[i][j][2] = min(size, derived + 1);
                    ans = max(ans, dp[i][j][2]);
                }
            }
        }

        return ans * ans;
    }
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

    }
};