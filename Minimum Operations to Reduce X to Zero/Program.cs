using System;

namespace Minimum_Operations_to_Reduce_X_to_Zero
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] nums = new int[]{1,1,4,2,3};
            int x = 5;
            int min = s.MinOperations(nums, x);
            Console.WriteLine($"Result: {min} - Expect: {2}");

            nums = new int[]{5,6,7,8,9};
            x = 4;
            min = s.MinOperations(nums, x);
            Console.WriteLine($"Result: {min} - Expect: {-1}");

            nums = new int[]{3,2,20,1,1,3};
            x = 10;
            min = s.MinOperations(nums, x);
            Console.WriteLine($"Result: {min} - Expect: {5}");


            Console.WriteLine("Hello World!");
        }
    }
}
