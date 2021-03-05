using System;

namespace Minimum_Initial_Energy_to_Finish_Tasks
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution = new Solution();
            int[][] task = new int[][] {new int[]{1, 7}, new int[]{2,8}, new int[]{3, 9},
            new int[]{4, 10}, new int[]{5, 11}, new int[]{6, 12}};
            int result = solution.MinimumEffort(task);
            Console.WriteLine($"Result: {result} - Expect: {27}");

            task = new int[][] {new int[]{1, 2}, new int[]{2,4}, new int[]{4,8}};
            result = solution.MinimumEffort(task);
            Console.WriteLine($"Result: {result} - Expect: {8}");

            task = new int[][] {new int[]{1, 3}, new int[]{2,4}, new int[]{10, 11}, new int[]{10, 12}, new int[]{8, 9}};
            result = solution.MinimumEffort(task);
            Console.WriteLine($"Result: {result} - Expect: {32}");

            Console.WriteLine("Hello World!");
        }
    }
}
