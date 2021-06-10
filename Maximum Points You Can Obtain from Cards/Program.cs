using System;

namespace Maximum_Points_You_Can_Obtain_from_Cards
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs;
            rs = s.MaxScore(new int[] { 1, 2, 3, 4, 5, 6, 1 }, 3);
            Console.WriteLine($"Result: {rs} - Expect: {12}");

            rs = s.MaxScore(new int[] { 2, 2, 2 }, 2);
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            rs = s.MaxScore(new int[] { 1, 1000, 1 }, 1);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            rs = s.MaxScore(new int[] { 1, 79, 80, 1, 1, 1, 200, 1 }, 3);
            Console.WriteLine($"Result: {rs} - Expect: {202}");

            rs = s.MaxScore(new int[] { 9, 7, 7, 9, 7, 7, 9 }, 7);
            Console.WriteLine($"Result: {rs} - Expect: {55}");

            rs = s.MaxScore(new int[]{96,90,41,82,39,74,64,50,30}, 8);
            Console.WriteLine($"Result: {rs} - Expect: {536}");
        }
    }
}
