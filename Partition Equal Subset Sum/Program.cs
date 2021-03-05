using System;

namespace Partition_Equal_Subset_Sum
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution= new Solution();
            int[] nums = new int[]{1, 5, 11, 5};
            bool result =solution.CanPartition(nums);
            Console.WriteLine($"Result: {result} - Expect: {true}");

            nums = new int[]{1, 2, 3, 5};
            result = solution.CanPartition(nums);
            Console.WriteLine($"Result: {result} - Expect: {false}");

            Console.WriteLine("Hello World!");
        }
    }
}
