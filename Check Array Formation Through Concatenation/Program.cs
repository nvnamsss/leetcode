using System;

namespace Check_Array_Formation_Through_Concatenation
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution=  new Solution();
            int[] arr = new int[]{91, 4, 64, 78};
            int[][] pieces = new int[][]{new int[]{78}, new int[]{4, 64}, new int[]{91}};
            bool rs = solution.CanFormArray(arr, pieces);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            arr = new int[]{49,18,16};
            pieces = new int[][] {new int[]{ 16, 18, 49}};
            rs = solution.CanFormArray(arr, pieces);
            Console.WriteLine($"Result: {rs} - Expect: {false}");


            Console.WriteLine("Hello World!");
        }
    }
}
