using System;

namespace Determine_if_Two_Strings_Are_Close
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution=  new Solution();
            string w1 = "abc";
            string w2 = "bca";
            bool rs = solution.CloseStrings(w1, w2);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            w1 = "a";
            w2 = "aa";
            rs = solution.CloseStrings(w1, w2);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            w1 = "cabbba";
            w2 = "abbccc";
            rs = solution.CloseStrings(w1, w2);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            w1 = "cabbba";
            w2 = "aabbss";
            rs = solution.CloseStrings(w1, w2);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            w1 = "abbbzcf";
            w2 = "babzzcz";
            rs = solution.CloseStrings(w1, w2);
            Console.WriteLine($"Result: {rs} - Expect: {false}");
        }
    }
}
