using System;

namespace Global_and_Local_Inversions
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] A = new int[]{1,0,2};
            bool rs = s.IsIdealPermutation(A);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            A = new int[]{1,2,0};
            rs = s.IsIdealPermutation(A);
            Console.WriteLine($"Result: {rs} - Expect: {false}");
        }
    }
}
