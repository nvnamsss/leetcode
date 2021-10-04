/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<pair<int, int>> directions = vector<pair<int, int>>{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int rs = 0;
        map<pair<int, int>, vector<int>> adjacency;
        // vector<vector<vector<int>>> adjacency =  vector<vector<int>>(n, vector<int>(n));
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    int size = 0;
                    set<pair<int, int>> bound;
                    dfs(grid, visited, i, j, bound, size);
                    for (auto &&v : bound)
                    {
                        if (adjacency.find(v) == adjacency.end())
                        {
                            adjacency.insert({v, vector<int>{}});
                        }
                        adjacency[v].push_back(size);
                    }
                    rs = max(rs, size);
                }
            }
        }

        if (rs < n * n) rs = rs + 1;

        for (auto &&v : adjacency)
        {
            int total = 1;
            for (int i = 0; i < v.second.size(); i++)
            {
                total = total + v.second[i];
            }
            rs = max(rs, total);
        }

        return rs;
    }

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, set<pair<int, int>> &adjacency, int &size)
    {
        if (visited[m][n])
            return;

        visited[m][n] = true;
        size++;
        int length = grid.size();
        for (int i = 0; i < 4; i++)
        {
            int x = m + directions[i].first;
            int y = n + directions[i].second;
            if (x < 0 || x >= length || y < 0 || y >= length)
                continue;
            if (grid[x][y] == 0)
            {
                if (adjacency.find({x, y}) == adjacency.end())
                    adjacency.insert({x, y});
            }
            else
            {
                dfs(grid, visited, x, y, adjacency, size);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = vector<vector<int>>{
        {1, 1},
        {0, 1}};
    int rs = s.largestIsland(grid);
    cout << "rs: " << rs << " expect: 4" << endl;

    grid = vector<vector<int>>{
        {0, 0},
        {0, 0}};
    rs = s.largestIsland(grid);
    cout << "rs: " << rs << " expect: 1" << endl;

    grid = vector<vector<int>>{
        {1, 0},
        {0, 1}};
    rs = s.largestIsland(grid);
    cout << "rs: " << rs << " expect: 3" << endl;
}