#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    bool dfs(vector<vector<int>> &grid, vector<vector<int>> &dp, vector<vector<bool>>& visited, int x, int y)
    {
        visited[x][y] = true;

        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }

        bool ans = false;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < 0 || ny < 0 || nx == m || ny == n || grid[nx][ny] == 1 || visited[nx][ny]) {
                continue;
            }
            bool unsurrounded = dfs(grid, dp, visited, nx, ny);
            ans = ans || unsurrounded;
        }

        dp[x][y] = ans;

        return ans;
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = !grid[0][i];
            dp[m-1][i] = !grid[m-1][i];
        }
        
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = !grid[i][0];
            dp[i][n-1] = !grid[i][n-1];
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] || grid[i][j] == 1)
                {
                    continue;
                }

                bool surrounded = !dfs(grid, dp, visited, i, j);
                if (surrounded)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    cout << s.closedIsland(grid) << endl;

    grid = {{1,1,0,1,1,1,1,1,1,1},{0,0,1,0,0,1,0,1,1,1},{1,0,1,0,0,0,1,0,1,0},{1,1,1,1,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,0},{0,0,0,0,1,1,0,0,0,0},{1,0,1,0,0,0,0,1,1,0},{1,1,0,0,1,1,0,0,0,0},{0,0,0,1,1,0,1,1,1,0},{1,1,0,1,0,1,0,0,1,0}};
    cout << s.closedIsland(grid) << endl;
}