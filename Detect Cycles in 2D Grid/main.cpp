#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m;
    int n;
    vector<vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, pair<int, int> last, pair<int, int> current) {
        if (visited[current.first][current.second]) {
            return true;
        }

        visited[current.first][current.second] = true;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = current.first + directions[i][0];
            int ny = current.second + directions[i][1];

            if (nx < 0 || ny < 0 || nx == m || ny == n || (nx == last.first && ny == last.second) || grid[nx][ny] != grid[current.first][current.second]) {
                continue;
            }

            if (dfs(grid, visited, current, {nx, ny})) {
                return true;
            }
        }
        
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j]) {
                    continue;
                }
                
                if (dfs(grid, visited, {-1 ,-1}, {i, j})) {
                    return true;
                }
            }
            
        }
        
        return false;
    }
};