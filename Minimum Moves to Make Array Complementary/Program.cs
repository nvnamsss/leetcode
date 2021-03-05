using System;

namespace Minimum_Moves_to_Make_Array_Complementary
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] array = new int[] { 1, 2, 4, 3 };
            int limit = 4;
            int result = s.MinMoves(array, limit);
            Console.WriteLine($"Result: {result} - Expect: {1}");

            array = new int[] { 1, 2, 2, 1 };
            limit = 2;
            result = s.MinMoves(array, limit);
            Console.WriteLine($"Result: {result} - Expect: {2}");

            array = new int[] { 1, 2, 1, 2 };
            limit = 2;
            result = s.MinMoves(array, limit);
            Console.WriteLine($"Result: {result} - Expect: {0}");

            array = new int[] {1,2,1,2, 3, 5, 2, 1, 6, 4};
            limit = 6;
                       result = s.MinMoves(array, limit);
            Console.WriteLine($"Result: {result} - Expect: {4}");

            Console.WriteLine("Hello World!");
        }
    }
}
