using System;

namespace Remove_Duplicate_Letters
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "cbacdcbc";

            Solution s = new Solution();
            string output = s.RemoveDuplicateLetters(input);

            Console.WriteLine($"Output: {output}");
            Console.WriteLine("Hello World!");
        }
    }
}
