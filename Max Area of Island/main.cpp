#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m = 0;
    int n = 0;
    vector<vector<int>> directions = vector<vector<int>>{
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        int ans = 0;
        visited[r][c] = true;

        for (int i = 0; i < directions.size(); i++)
        {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            if (nr < 0 || nr == m || nc < 0 || nc == n || visited[nr][nc] || grid[nr][nc] == 0) continue;
            ans = dfs(grid, visited, r, c);
        }
                
        return ans + 1;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans = max(ans, dfs(grid, visited, i, j));
                }
            }
            
        }

        return ans;
    }
};