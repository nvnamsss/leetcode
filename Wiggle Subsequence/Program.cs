using System;

namespace Wiggle_Subsequence
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] nums = new int[]{1,7,4,9,2,5};
            int rs = s.WiggleMaxLength(nums);
            Console.WriteLine($"Result: {rs} - Expect: {6}");

            nums = new int[] {1,17,5,10,13,15,10,5,16,8};
            rs = s.WiggleMaxLength(nums);
            Console.WriteLine($"Result: {rs} - Expect: {7}");

            nums = new int[] {1,2,3,4,5,6,7,8,9};
            rs = s.WiggleMaxLength(nums);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            nums = new int[]{0,0};
            rs = s.WiggleMaxLength(nums);
            Console.WriteLine($"Result: {rs} - Expect: {1}");
            nums = new int[]{3,3,3,2,5};
            rs = s.WiggleMaxLength(nums);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
        }
    }
}
