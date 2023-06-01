/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.



Example 1:


Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation:
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
Example 2:


Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct move
    {
        int x;
        int y;
        int r;
        int d;
        move(int x, int y, int r, int d)
        {
            this->x = x;
            this->y = y;
            this->r = r;
            this->d = d;
        }
    };

    vector<vector<int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int astar(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<move> pq;
        return -1;
    }

public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<unordered_set<int>>> visited = vector<vector<unordered_set<int>>>(m, vector<unordered_set<int>>(n));
        queue<move> q;
        q.push(move(0, 0, k, 0));

        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                move mv = q.front();
                if (mv.x == m - 1 && mv.y == n - 1)
                {
                    return ans;
                }
                q.pop();

                if (visited[mv.x][mv.y].count(mv.r))
                {
                    continue;
                }

                visited[mv.x][mv.y].insert(mv.r);
                if (grid[mv.x][mv.y])
                {
                    mv.r--;
                    if (mv.r == 0)
                    {
                        continue;
                    }
                }

                for (int j = 0; j < directions.size(); j++)
                {
                    int nx = mv.x + directions[j][0];
                    int ny = mv.y + directions[j][1];
                    int r = mv.r;
                    if ((mv.d != j && (mv.d + j) % 2 == 0) || nx < 0 || ny < 0 || nx == m || ny == n)
                    {
                        continue;
                    }

                    q.push(move(nx, ny, r, j));
                }
            }
            ans++;
        }

        return -1;
    }
};