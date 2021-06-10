using System;

namespace Count_Triplets_That_Can_Form_Two_Arrays_of_Equal_XOR
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.CountTriplets(new int[] { 2, 3, 1, 6, 7 });
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            rs = s.CountTriplets(new int[] { 1, 1, 1, 1, 1 });
            Console.WriteLine($"Result: {rs} - Expect: {10}");

            rs = s.CountTriplets(new int[] { 2, 3 });
            Console.WriteLine($"Result: {rs} - Expect: {10}");

            rs = s.CountTriplets(new int[] { 1, 3, 5, 7, 9 });
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            rs = s.CountTriplets(new int[]{7,11,12,9,5,2,7,17,22});
            Console.WriteLine($"Result: {rs} - Expect: {8}");

        }
    }
}
