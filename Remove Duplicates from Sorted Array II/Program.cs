using System;

namespace Remove_Duplicates_from_Sorted_Array_II
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] arr = new int[] {1,1,1,2,2,3};
            int rs = s.RemoveDuplicates(arr);
            Console.WriteLine($"Result: {rs} - Expect: {5}");
            s.Print(arr);

            arr = new int[]{0,0,1,1,1,1,2,3,3};
            rs = s.RemoveDuplicates(arr);
            Console.WriteLine($"Result: {rs} - Expect: {7}");
            s.Print(arr);

            arr = new int[]{};
            rs = s.RemoveDuplicates(arr);
            Console.WriteLine($"Result: {rs} - Expect: {0}");
            s.Print(arr);

            Console.WriteLine("Hello World!");
        }
    }
}
