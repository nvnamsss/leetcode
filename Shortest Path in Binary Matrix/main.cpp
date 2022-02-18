#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = vector<vector<int>>{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
        if (grid[m - 1][n - 1]) {
            return -1;
        }
        dp[m - 1][n - 1] = 1;
        queue<pair<int, int>> q;
        q.push({m - 1, n - 1});
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                pair<int, int> coor = q.front();
                q.pop();
                for (int j = 0; j < directions.size(); j++)
                {
                    int x = coor.first + directions[j][0];
                    int y = coor.second + directions[j][1];
                    if (x < 0 || y < 0 || x == m || y == n || grid[x][y] == 1)
                    {
                        continue;
                    }

                    if (dp[x][y] == -1) {
                        dp[x][y] = dp[coor.first][coor.second] + 1;
                        q.push({x, y});
                    } else {
                        dp[x][y] = min(dp[x][y], dp[coor.first][coor.second] + 1);
                    }
                }
            }
        }
        return  dp[0][0];
    }
};