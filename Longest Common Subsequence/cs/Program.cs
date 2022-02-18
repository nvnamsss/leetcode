using System;

namespace cs
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.LongestCommonSubsequence("abcde", "ace");
            Console.WriteLine($"Result: {rs}");
        }
    }
}
