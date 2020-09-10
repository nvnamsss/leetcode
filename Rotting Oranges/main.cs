/*
Given a 2D grid, each cell is either a zombie 1 or a human 0. Zombies can turn adjacent (up/down/left/right) human beings into zombies every hour. Find out how many hours does it take to infect all humans?

Example:

Input:
[[0, 1, 1, 0, 1],
 [0, 1, 0, 1, 0],
 [0, 0, 0, 0, 1],
 [0, 1, 0, 0, 0]]

Output: 2

Explanation:
At the end of the 1st hour, the status of the grid:
[[1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1],
 [0, 1, 0, 1, 1],
 [1, 1, 1, 0, 1]]

At the end of the 2nd hour, the status of the grid:
[[1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1],
 [1, 1, 1, 1, 1]]
*/

using System;
using System.Collections.Generic;

public class Solution {
    public int OrangesRotting(int[][] grid) {
        Queue<KeyValuePair<int, int>> q = new Queue<KeyValuePair<int, int>>();
        int m = grid.Length;
        int n = grid[0].Length;
        int minutes = 0;
        int fresh = 0;

        bool[][] visited = new bool[m][];
        int[][] direction = new int[4][];
        direction[0] = new int[]{1, 0};
        direction[1] = new int[]{-1, 0};
        direction[2] = new int[]{0, 1};
        direction[3] = new int[]{0, -1};

        for (int loop = 0; loop < m; loop++)
        {
            visited[loop] = new bool[n];
            for (int loop2 = 0; loop2 < n; loop2++)
            {
                if (grid[loop][loop2] == 2)
                {
                    KeyValuePair<int, int> key = new KeyValuePair<int, int>(loop, loop2);
                    q.Enqueue(key);
                    visited[loop][loop2] = true;

                }
                else if (grid[loop][loop2] == 1) fresh++;
            }
        }
        
        while (q.Count > 0)
        {
            if (fresh == 0) return minutes;
            int count = q.Count;
            for (int loop = 0; loop < count; loop++)
            {
                KeyValuePair<int, int> k = q.Dequeue();
                for (int loop2 = 0; loop2 < direction.Length; loop2++)
                {
                    int x = k.Key + direction[loop2][0];
                    int y = k.Value + direction[loop2][1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;

                    if (!visited[x][y] && grid[x][y] == 1)
                    {
                        KeyValuePair<int, int> rotting = new KeyValuePair<int, int>(x, y);
                        q.Enqueue(rotting);
                        fresh--;
                        visited[x][y] = true;
                    }
                }
            }
            
            minutes++;
        }
        
        if (fresh > 0) return -1;

        return 0;
    }
}