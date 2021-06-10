using System;

namespace cs
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.LongestConsecutive(new int[] { 1, 100, 4, 200, 3, 2 });
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            rs = s.LongestConsecutive(new int[] { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 });
            Console.WriteLine($"Result: {rs} - Expect: {9}");

            rs = s.LongestConsecutive(new int[] { });
            Console.WriteLine($"Result: {rs} - Expect: {0}");


            rs = s.LongestConsecutive(new int[] { 1 });
            Console.WriteLine($"Result: {rs} - Expect: {1}");
        }
    }
}
