using System;

namespace World_Ladder
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            string begin = "hit";
            string end = "cog";
            string[] words = new string[] { "hot", "dot", "dog", "lot", "log", "cog" };
            int rs = s.LadderLength(begin, end, words);
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            words = new string[] { "hot", "dot", "dog", "lot", "log" };
            rs = s.LadderLength(begin, end, words);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            words = new string[] { "mot", "dot", "dog", "lot", "log", "cog" };
            rs = s.LadderLength(begin, end, words);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

        }
    }
}
