using System;

namespace Stone_Game_VII
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] stones = new int[] { 5, 3, 1, 4, 2 };
            int result = s.StoneGameVII(stones);
            Console.WriteLine($"Result: {result} - Expect: {6}");

            stones = new int[] { 7, 90, 5, 1, 100, 10, 10, 2 };
            result = s.StoneGameVII(stones);
            Console.WriteLine($"Result: {result} - Expect: {122}");

        }
    }
}
