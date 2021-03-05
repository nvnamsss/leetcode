using System;

namespace Ways_to_Make_a_Fair_Array
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] arr = new int[]{2,1,6,4};
            int result = s.WaysToMakeFair(arr);
            Console.WriteLine($"Result: {result} - Expect: {1}");

            arr = new int[]{1, 1, 1};
            result = s.WaysToMakeFair(arr);
            Console.WriteLine($"Result: {result} - Expect: {3}");

            arr = new int[]{1, 2, 3};
            result = s.WaysToMakeFair(arr);
            Console.WriteLine($"Result: {result} - Expect: {0}");

            arr = new int[]{1};
            result = s.WaysToMakeFair(arr);
            Console.WriteLine($"Result: {result} - Expect: {1}");

            Console.WriteLine("Hello World!");
        }
    }
}
