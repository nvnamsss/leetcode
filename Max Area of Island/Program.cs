using System;

namespace Max_Area_of_Island
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[][] grid = new int[][]{
                new int[]{1,1,0,0,0},
                new int[]{1,1,0,0,0},
                new int[]{0,0,0,1,1},
                new int[]{0,0,0,1,1},
            };

            int rs = s.MaxAreaOfIsland(grid);
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            grid = new int[][] {
                new int[]{0,0,1,0,0,0,0,1,0,0,0,0,0},
                new int[]{0,0,0,0,0,0,0,1,1,1,0,0,0},
                new int[]{0,1,1,0,1,0,0,0,0,0,0,0,0},
                new int[]{0,1,0,0,1,1,0,0,1,0,1,0,0},
                new int[]{0,1,0,0,1,1,0,0,1,1,1,0,0},
                new int[]{0,0,0,0,0,0,0,0,0,0,1,0,0},
                new int[]{0,0,0,0,0,0,0,1,1,1,0,0,0},
                new int[]{0,0,0,0,0,0,0,1,1,0,0,0,0},
            };

            rs = s.MaxAreaOfIsland(grid);
            Console.WriteLine($"Result: {rs} - Expect: {6}");
        }
    }
}
