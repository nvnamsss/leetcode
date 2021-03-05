using System;

namespace Squares_of_a_Sorted_Array
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] array = new int[] { -4, -1, 0, 3, 10 };
            int[] rs = s.SortedSquares(array);
            s.Print(rs);

            array = new int[] { -7, -3, 2, 3, 11 };
            rs = s.SortedSquares(array);
            s.Print(rs);

            array = new int[] { 1 };
            rs = s.SortedSquares(array);
            s.Print(rs);

            array = new int[] { -5, -4, -3, -2, -1 };
            rs = s.SortedSquares(array);
            s.Print(rs);

            array = new int[] { -1,2,2 };
            rs = s.SortedSquares(array);
            s.Print(rs);

            Console.WriteLine("Hello World!");
        }
    }
}
