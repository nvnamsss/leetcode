using System;

namespace Arithmetic_Slices_II___Subsequence
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] slice = new int[] { 2, 4, 6, 8, 10 };
            int rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {7}");

            slice = new int[] { 2, 4, 6, 8, 10, 12, 14, 16, 18 };
            rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {41}");

            slice = new int[] { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
            rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {55}");

            slice = new int[] { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22 };
            rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {72}");

            slice = new int[] { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 };
            rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {90}");

            slice = new int[] { 7, 7, 7, 7 };
            rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            slice = new int[] { 7, 7, 7, 7, 7 };
            rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {16}");

            slice = new int[] { 7, 7, 7, 7, 7, 7 };
            rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {42}");

            slice = new int[] { 2, 2, 3, 4 };
            rs = s.NumberOfArithmeticSlices(slice);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

        }
    }
}
