using System;

namespace Diagonal_Traverse
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[][] matrix = new int[][]{
                new int[]{1,2,3},
                new int[]{4,5,6},
                new int[]{7,8,9},
            };

            int[] result = s.FindDiagonalOrder(matrix);
            s.Print(result);

            matrix = new int[][] {
                new int[]{1, 2},
                new int[]{4, 5},
                new int[]{7, 8},
            };

            result = s.FindDiagonalOrder(matrix);
            s.Print(result);

            matrix = new int[][]{
                new int[]{1,2,3,4,5,6}
            };
            result = s.FindDiagonalOrder(matrix);
            s.Print(result);
            
            Console.WriteLine("Hello World!");
        }
    }
}
