using System;

namespace Smallest_Integer_Divisible_by_K
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.SmallestRepunitDivByK(3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            Console.WriteLine("Hello World!");
        }
    }
}
