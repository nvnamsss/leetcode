using System;

namespace Lexicographically_Smallest_String_After_Applying_Operations
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            string input = "5525";
            int a = 9;
            int b = 2;
            string rs = s.FindLexSmallestString(input, a, b);
            Console.WriteLine($"Testcase: {input} - Result: {rs} - Expect: {2050}");

            input = "74";
            a = 5;
            b = 1;
            rs = s.FindLexSmallestString(input, a, b);
            Console.WriteLine($"Testcase: {input} - Result: {rs} - Expect: {24}");

            input = "0011";
            a = 4;
            b = 2;
            rs = s.FindLexSmallestString(input, a, b);
            Console.WriteLine($"Testcase: {input} - Result: {rs} - Expect: {"0011"}");

            input = "43987654";
            a = 7;
            b = 3;
            rs = s.FindLexSmallestString(input, a, b);
            Console.WriteLine($"Testcase: {input} - Result: {rs} - Expect: {"00553311"}");

            Console.WriteLine("Hello World!");
        }
    }
}
