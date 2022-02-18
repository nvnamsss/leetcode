#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = vector<vector<int>>{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m;
    int n;
    void recursive(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        visited[i][j] = true;
        for (int k = 0; k < directions.size(); k++)
        {
            int x = i + directions[k][0];
            int y = j + directions[k][1];
            if (x < 0 || y < 0 || x == m || y == n || visited[x][y] || grid[x][y] == '0') {
                continue;
            }

            recursive(grid, visited, x, y);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    recursive(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};