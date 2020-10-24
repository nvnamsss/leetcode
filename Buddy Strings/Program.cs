using System;

namespace Buddy_Strings
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            string a = "ab";
            string b = "ba";
            bool rs = s.BuddyStrings(a, b);
            Console.WriteLine($"Buddy Strings: result: {rs} - expect: {true}");

            a = "ab";
            b = "ab";
            rs = s.BuddyStrings(a, b);
            Console.WriteLine($"Buddy Strings: result: {rs} - expect: {false}");

            a = "a";
            b = "a";
            rs = s.BuddyStrings(a, b);
            Console.WriteLine($"Buddy Strings: result: {rs} - expect: {false}");

            a = "aa";
            b = "aa";
            rs = s.BuddyStrings(a, b);
            Console.WriteLine($"Buddy Strings: result: {rs} - expect: {true}");
            a = "abcaa";
            b = "abcbb";
            rs = s.BuddyStrings(a, b);
            Console.WriteLine($"Buddy Strings: result: {rs} - expect: {true}");
        }
    }
}
