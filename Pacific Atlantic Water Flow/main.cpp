/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.



Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.


Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void recursive(vector<vector<int>> &heights, vector<vector<bool>> &reachable, int x, int y)
    {
        reachable[x][y] = true;
        int m = heights.size();
        int n = heights[0].size();

        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || reachable[nx][ny] || heights[nx][ny] < heights[x][y])
            {
                continue;
            }
            recursive(heights, reachable, nx, ny);
        }

    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacificReachable = vector<vector<bool>>(m, vector<bool>(n));
        vector<vector<bool>> atlanticReachable = vector<vector<bool>>(m, vector<bool>(n));
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            recursive(heights, pacificReachable, i, 0);
            recursive(heights, atlanticReachable, i, n - 1);
        }

        for (int i = 0; i < n; i++)
        {
            recursive(heights, pacificReachable, 0, i);
            recursive(heights, atlanticReachable, m - 1, i);
        }


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (atlanticReachable[i][j] && pacificReachable[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    s.pacificAtlantic(matrix);

    matrix = {{1, 1}, {1, 1}, {1, 1}};
    s.pacificAtlantic(matrix);
}