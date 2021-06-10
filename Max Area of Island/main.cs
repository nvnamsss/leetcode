/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

using System;
public class Solution
{
    int[][] direction = new int[][]{
        new int[]{1,0},
        new int[]{-1,0},
        new int[]{0,1},
        new int[]{0,-1},
    };
    int max;
    int m, n;
    int area;
    public int MaxAreaOfIsland(int[][] grid)
    {
        max = 0;
        m = grid.Length;
        n = grid[0].Length;
        bool[][] visited = new bool[m][];
        for (int loop = 0; loop < m; loop++)
        {
            visited[loop] = new bool[n];
        }

        for (int loop = 0; loop < m; loop++)
        {
            for (int loop2 = 0; loop2 < n; loop2++)
            {
                if (loop == 3 && loop2 == 8) {
                    Console.WriteLine("a");
                }
                if (!visited[loop][loop2] && grid[loop][loop2] == 1)
                {
                    area = 0;
                    dfs(grid, loop, loop2, visited);
                }
            }
        }

        return max;
    }

    private void dfs(int[][] grid, int h, int w, bool[][] visited)
    {
        visited[h][w] = true;
        area = area + 1;
        max = Math.Max(max, area);
        
        for (int loop = 0; loop < direction.Length; loop++)
        {
            int[] d = direction[loop];
            int x = h + d[0];
            int y = w + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 1)
            {
                dfs(grid, x, y, visited);
            }
        }
    }
}