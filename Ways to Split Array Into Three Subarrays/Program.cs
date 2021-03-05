using System;

namespace Ways_to_Split_Array_Into_Three_Subarrays
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] nums = new int[] { 1, 1, 1, 3 };
            int rs = s.WaysToSplit(nums);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            nums = new int[] { 1, 2, 2, 2, 5, 0 };
            rs = s.WaysToSplit(nums);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            nums = new int[] { 3, 2, 1 };
            rs = s.WaysToSplit(nums);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            nums = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            rs = s.WaysToSplit(nums);
            Console.WriteLine($"Result: {rs} - Expect: {12}");

            nums = new int[] { 0, 0, 0, 0, 0 };
            rs = s.WaysToSplit(nums);
            Console.WriteLine($"Result: {rs} - Expect: {6}");

            nums = new int[] { 1, 3, 9, 3, 10, 5, 7, 7 };
            rs = s.WaysToSplit(nums);
            Console.WriteLine($"Result: {rs} - Expect: {6}");

            nums = new int[] { 1793, 6674, 3412, 2383, 3274, 9438, 77, 3603, 2797, 2013, 4324, 2204, 9189, 5010, 6981, 1623 };
            rs = s.WaysToSplit(nums);
            Console.WriteLine($"Result: {rs} - Expect: {23}");

            nums = new int[]{3, 1, 9, 3, 10, 5, 7, 7};
            rs = s.WaysToSplit(nums);

        }
    }
}
