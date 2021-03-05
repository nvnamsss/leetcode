using System;

namespace Jump_Game_III
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution = new Solution();
            int[] arr = new int[]{4,2,3,0,3,1,2};
            int start = 5;
            bool rs = solution.CanReach(arr, start);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            start = 0;
            rs = solution.CanReach(arr, start);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            arr = new int[]{3,0,2,1,2};
            start = 2;
            rs = solution.CanReach(arr, start);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            Console.WriteLine("Hello World!");
        }
    }
}
