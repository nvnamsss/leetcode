#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = vector<vector<int>>{{1, 0}, {0, 1}};
    int recursive(vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n, int x, int y)
    {
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }

        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < m && ny < n) {
                int val = recursive(grid, dp, m, n, nx, ny);
                if (dp[x][y] != -1) {
                    dp[x][y] = min(dp[x][y], val + grid[x][y]);
                } else {
                    dp[x][y] = val + grid[x][y];
                }
            }
        }

        return dp[x][y];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        return recursive(grid, dp, m, n, 0, 0);
    }
};