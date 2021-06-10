using System;

namespace Maximum_Erasure_Value
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.MaximumUniqueSubarray(new int[] { 4, 2, 4, 5, 6 });
            Console.WriteLine($"Result: {rs} - Expect: {17}");

            rs = s.MaximumUniqueSubarray(new int[] { 5, 2, 1, 2, 5, 2, 1, 2, 5 });
            Console.WriteLine($"Result: {rs} - Expect: {8}");

            rs = s.MaximumUniqueSubarray(new int[] { 5 });
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            rs = s.MaximumUniqueSubarray(new int[]{10000,1,10000,1,1,1,1,1,1});
            Console.WriteLine($"Result: {rs} - Expect: {10001}");
        }
    }
}
