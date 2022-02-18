#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = vector<vector<int>>{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int turn = -1;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                pair<int, int> p = q.front();
                q.pop();

                for (int i = 0; i < directions.size(); i++)
                {
                    int nr = p.first + directions[i][0];
                    int nc = p.second + directions[i][1];
                    if (nr < 0 || nc < 0 || nr == m || nc == n || visited[nr][nc] || grid[nr][nc] != 1)
                        continue;
                    fresh--;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            turn++;

        }

        if (fresh > 0)
            return -1;

        return turn;
    }
};