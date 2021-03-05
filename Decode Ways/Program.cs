using System;

namespace Decode_Ways
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int result = s.NumDecodings("12");
            Console.WriteLine($"Result: {result} - Expect: {2}");

            result = s.NumDecodings("226");
            Console.WriteLine($"Result: {result} - Expect: {3}");

            result = s.NumDecodings("0");
            Console.WriteLine($"Result: {result} - Expect: {0}");

            result = s.NumDecodings("1");
            Console.WriteLine($"Result: {result} - Expect: {1}");

            result = s.NumDecodings("5131");
            Console.WriteLine($"Result: {result} - Expect: {2}");

            result = s.NumDecodings("1251312");
            Console.WriteLine($"Result: {result} - Expect: {12}");

            result = s.NumDecodings("102");
            Console.WriteLine($"Result: {result} - Expect: {1}");

            result = s.NumDecodings("53124131");
            Console.WriteLine($"Result: {result} - Expect: {6}");

            result =s .NumDecodings("5213124131");
            Console.WriteLine($"Result: {result} - Expect: {6}");
        }
    }
}
