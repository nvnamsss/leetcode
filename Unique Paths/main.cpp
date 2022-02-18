/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = vector<vector<int>>{{1,0}, {0, 1}};

    int recursive(vector<vector<int>>& dp, int m, int n, int x, int y) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int ans = 0;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < m && ny < n) {
                ans += recursive(dp, m, n, nx, ny);
            }
        }

        dp[x][y] = ans;
        return dp[x][y];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
        dp[m - 1][n - 1] = 1;

        return recursive(dp, m, n, 0, 0);
    }
};