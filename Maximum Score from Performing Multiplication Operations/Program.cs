using System;

namespace Maximum_Score_from_Performing_Multiplication_Operations
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] nums = new int[]{1,2,3};
            int[] multipliers = new int[]{3,2,1};

            int rs = s.MaximumScore(nums, multipliers);
            Console.WriteLine($"Result: {rs} - Expect: {14}");

            nums = new int[]{-5,-3,-3,-2,7,1};
            multipliers = new int[]{-10,-5,3,4,6};
            rs = s.MaximumScore(nums, multipliers);
            Console.WriteLine($"Result: {rs} - Expect: {102}");

        }
    }
}
