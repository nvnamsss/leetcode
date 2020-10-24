using System;

namespace Largest_Substring_Between_Two_Equal_Characters
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            string input = "aa";
            int result = s.MaxLengthBetweenEqualCharacters(input);
            Console.WriteLine($"Testcase: {input} - Result: {result} - expect: {0}");

            input = "abca";
            result = s.MaxLengthBetweenEqualCharacters(input);
            Console.WriteLine($"Testcase: {input} - Result: {result} - expect: {2}");

            input = "cbzxy";
            result = s.MaxLengthBetweenEqualCharacters(input);
            Console.WriteLine($"Testcase: {input} - Result: {result} - expect: {-1}");

            input = "cabbac";
            result = s.MaxLengthBetweenEqualCharacters(input);
            Console.WriteLine($"Testcase: {input} - Result: {result} - expect: {4}");

            input = "mgntdygtxrvxjnwksqhxuxtrv";
            result = s.MaxLengthBetweenEqualCharacters(input);
            Console.WriteLine($"Testcase: {input} - Result: {result} - expect: {18}");

            Console.WriteLine("Hello World!");
        }
    }
}
