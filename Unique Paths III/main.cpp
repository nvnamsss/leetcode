/*
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:


Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int rs = 0;
    void recursive(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, int nonobstacle, int x, int y)
    {
        if (grid[x][y] == 2)
        {
            if (nonobstacle == -1)
            {
                rs++;
            }
            return;
        }

        visited[x][y] = true;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < 0 || ny < 0 || nx == m || ny == n || visited[nx][ny])
            {
                continue;
            }

            recursive(grid, visited, m, n, nonobstacle - 1, nx, ny);
        }

        visited[x][y] = false;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        pair<int, int> start;
        pair<int, int> end;
        int nonobstacle = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                switch (grid[i][j])
                {
                case 0:
                    nonobstacle++;
                    break;
                case 1:
                    start = {i, j};
                    break;
                case 2:
                    end = {i, j};
                    break;
                case -1:
                    visited[i][j] = true;
                    break;
                }
            }
        }

        recursive(grid, visited, m, n, nonobstacle, start.first, start.second);
        return rs;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {1,0,0,0},
        {0,0,0,0},
        {0,0,2,-1}
    };
    int rs = s.uniquePathsIII(grid);
    cout << rs << endl;
}