using System;

namespace Longest_Mountain_in_Array
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] arr = new int[]{2,1,4,7,3,2,5};
            int rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            arr = new int[]{2,3,5,4,1,6,4};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            arr = new int[]{2,2,2};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            arr = new int[]{2};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            arr = new int[]{0,1,2,3,4,5,6,7,8,9};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            arr = new int[]{2, 3};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            arr = new int[]{0,1,2,3,4,5,6,7,8,9,1};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {11}");

            arr = new int[]{9,8,7,6,5,4,3,2,1,0};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            arr = new int[]{0,1,0,1};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            arr = new int[]{0,2,0,2,1,2,3,4,4,1};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            arr = new int[]{875,884,239,731,723,685};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            arr = new int[]{3, 3, 1};
            rs = s.LongestMountain(arr);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

        }
    }
}
