using System;

namespace Search_in_Rotated_Sorted_Array_II
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[]{2,5,6,0,0,1,2};
            Solution s = new Solution();
            bool rs= s.Search(arr, 0);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            arr = new int[] {2,5,6,0,0,1,2};
            rs = s.Search(arr, 3);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            arr = new int[] {};
            rs = s.Search(arr, 3);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            arr = new int[] {1};
            rs = s.Search(arr, 0);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            Console.WriteLine("Hello World!");
        }
    }
}
