using System;

namespace Course_Schedule
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[][] prerequisites = new int[][]{
                new int[]{1, 0},
            };
            bool rs = s.CanFinish(2, prerequisites);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            prerequisites = new int[][] {
                new int[]{1, 0},
                new int[]{0, 1},
            };
            rs = s.CanFinish(2, prerequisites);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            prerequisites = new int[][] {
                new int[]{0, 1},
            };
            rs = s.CanFinish(2, prerequisites);
            Console.WriteLine($"Result: {rs} - Expect: {true}");
        }
    }
}
