using System;

namespace Number_of_Longest_Increasing_Subsequence
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] nums = new int[] { 1, 3, 5, 4, 7 };
            int rs = s.FindNumberOfLIS(nums);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            nums = new int[] { 2, 2, 2, 2, 2 };
            rs = s.FindNumberOfLIS(nums);
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            nums = new int[] { 1,2,4,3,5,4,7,2};
            rs = s.FindNumberOfLIS(nums);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            Console.WriteLine("Hello World!");
        }
    }
}
