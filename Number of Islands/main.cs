/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

public class Solution {
            static bool[][] visited;
        static char[][] g;
        static int h;
        static int w;
        public static void init(char[][] grid)
        {
            g = grid;
            h = g.Length;
            w = g[0].Length;
            visited = new bool[h][];
            for (int loop = 0; loop < visited.Length; loop++)
            {
                visited[loop] = new bool[w];
            }
        }


        private void dfs(int r, int c)
        {
            if (r == -1 || c == -1) return;
            if (r >= h || c >= w || g[r][c] == '0' || visited[r][c]) return;

            visited[r][c] = true;
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        }

        public int NumIslands(char[][] grid) {
                       if (grid.Length == 0) return 0;
            init(grid);

            int islands = 0;

            for (int loop = 0; loop < h; loop++)
            {
                for (int loop2 = 0; loop2 < w; loop2++)
                {
                    if (!visited[loop][loop2] && g[loop][loop2] == '1')
                    {
                        islands += 1;
                        dfs(loop, loop2);
                    }
                }
            }

            return islands;
        }
}