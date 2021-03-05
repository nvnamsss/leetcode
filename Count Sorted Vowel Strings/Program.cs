using System;

namespace Count_Sorted_Vowel_Strings
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            Console.WriteLine(s.combination(8,4));
            Console.WriteLine(s.combination(7,3));

            Console.WriteLine($"Result: {s.CountVowelStrings(2)} - Expect: {15}");
            Console.WriteLine($"Result: {s.CountVowelStrings(3)} - Expect: {35}");
            Console.WriteLine($"Result: {s.CountVowelStrings(4)} - Expect: {70}");
            Console.WriteLine($"Result: {s.CountVowelStrings(33)} - Expect: {66045}");
            Console.WriteLine("Hello World!");
        }
    }
}
