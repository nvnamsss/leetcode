using System;

namespace Remove_Covered_Intervals
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[][] intervals = new int[][]{
                new int[]{1,4},
                new int[]{3,6},
                new int[]{2,8}
            };

            int rs = s.RemoveCoveredIntervals(intervals);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            intervals = new int[][]{
                new int[]{1,4},
                new int[]{2,3},
            };
            rs = s.RemoveCoveredIntervals(intervals);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            intervals = new int[][]{
                new int[]{0,10},
                new int[]{5,12},
            };
            rs = s.RemoveCoveredIntervals(intervals);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            intervals = new int[][]{
                new int[]{3,10},
                new int[]{4,10},
                new int[]{5,11},
            };
            rs = s.RemoveCoveredIntervals(intervals);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            intervals = new int[][]{
                new int[]{1,2},
                new int[]{1,4},
                new int[]{3,4},
            };
            rs = s.RemoveCoveredIntervals(intervals);
            Console.WriteLine($"Result: {rs} - Expect: {1}");
        }
    }
}
