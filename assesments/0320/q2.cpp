/*
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int get(vector<vector<int>> &mat, int i, int j)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            return 0;
        return mat[i][j];
    }

public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>(n));
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = mat[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int r1 = max(0, i - k) + 1;
                int c1 = max(0, j - k) + 1;
                int r2 = min(m - 1, i + k) + 1;
                int c2 = min(n - 1, j + k) + 1;
                ans[i][j] = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.matrixBlockSum(mat, 1);
}