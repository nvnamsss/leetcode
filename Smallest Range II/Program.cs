using System;

namespace Smallest_Range_II
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] A = new int[] { 1 };
            int rs = s.SmallestRangeII(A, 0);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            A = new int[] { 0, 10 };
            rs = s.SmallestRangeII(A, 2);
            Console.WriteLine($"Result: {rs} - Expect: {6}");

            A = new int[] { 1, 3, 6 };
            rs = s.SmallestRangeII(A, 3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            A = new int[] { 1, 7, 3, 2, 6, 34, 3, 1, 4, 5, 7 };
            rs = s.SmallestRangeII(A, 10);
            Console.WriteLine($"Result: {rs} - Expect: {13}");

            A = new int[] { 1, 2, 3, 2, 3, 34, 3, 2, 3, 2, 2 };
            rs = s.SmallestRangeII(A, 10);
            Console.WriteLine($"Result: {rs} - Expect: {13}");

            A = new int[] { 1, 32, 7, 8, 9, 34, 3, 2, 3, 2, 2 };
            rs = s.SmallestRangeII(A, 10);
            Console.WriteLine($"Result: {rs} - Expect: {13}");

            A = new int[] { 1, 32, 7, 8, 9, 34, 3, 2, 3, 2, 2 };
            rs = s.SmallestRangeII(A, 40);
            Console.WriteLine($"Result: {rs} - Expect: {33}");

            A = new int[] { 1, 32, 7, 8, 9, 34, 3, 2, 3, 2, 2 };
            rs = s.SmallestRangeII(A, 20);
            Console.WriteLine($"Result: {rs} - Expect: {17}");

            A = new int[] { 1, 32, 7, 8, 9, 34, 3, 2, 3, 2, 2 };
            rs = s.SmallestRangeII(A, 15);
            Console.WriteLine($"Result: {rs} - Expect: {8}");

            A = new int[] { 7, 8, 8 };
            rs = s.SmallestRangeII(A, 5);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            A = new int[] { 1, 4, 6, 4 };
            rs = s.SmallestRangeII(A, 3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            A = new int[] { 4, 1, 8, 10 };
            rs = s.SmallestRangeII(A, 3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            A = new int[] { 6, 4, 10 };
            rs = s.SmallestRangeII(A, 5);
            Console.WriteLine($"Result: {rs} - Expect: {6}");

            A = new int[] { 4, 12, 13 };
            rs = s.SmallestRangeII(A, 5);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            A = new int[] { 4, 3, 10, 2, 0 };
            rs = s.SmallestRangeII(A, 3);
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            A = new int[] { 1, 6, 6, 9 };
            rs = s.SmallestRangeII(A, 2);
            Console.WriteLine($"Result: {rs} - Expect: {4}");
        }
    }
}
