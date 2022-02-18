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
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> rs = vector<vector<int>>(m, vector<int>(n, 0));
        int dp[m][n + 1];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j + 1] = dp[i][j] + mat[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                // calculate
                for (int loop = -k; loop <= k; loop++)
                {
                    int h = i + loop;
                    if (h < 0 || h >= m)
                        continue;
                    int from = max(j - k, 0);
                    int to = min(j + k + 1, n);
                    int r = dp[h][to] - dp[h][from];
                    sum = sum + r;
                }

                // insert
                rs[i][j] = sum;
            }
        }

        return rs;
    }
};