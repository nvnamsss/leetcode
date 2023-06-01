/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, int &count)
    {
        visited[x][y] = true;
        count++;

        bool ans = (x == 0 || y == 0 || x == m - 1 || y == n - 1) && grid[x][y] == 1;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < 0 || ny < 0 || nx == m || ny == n || grid[x][y] == 0 || visited[x][y]) {
                continue;
            }

            bool walkable = dfs(grid, visited, nx, ny, count);
            ans = ans || walkable;
        }

        return ans;        
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] || grid[i][j] == 0) {
                    continue;
                }
                int count = 0;
                bool walkable = dfs(grid, visited, i, j, count);
                if (!walkable) {
                    ans += count;
                }
            }
            
        }
        return ans;
    }
};