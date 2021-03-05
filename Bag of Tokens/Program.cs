using System;

namespace Bag_of_Tokens
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int p = 50;
            int[] tokens = new int[]{100};
            int score = s.BagOfTokensScore(tokens, p);
            Console.WriteLine($"Result: {score} - Expect: {0}");

            p = 150;
            tokens = new int[]{100, 200};
            score = s.BagOfTokensScore(tokens, p);
            Console.WriteLine($"Result: {score} - Expect: {1}");

            p = 200;
            tokens = new int[]{100, 200, 300, 400};
            score = s.BagOfTokensScore(tokens, p);
            Console.WriteLine($"Result: {score} - Expect: {2}");

            p = 50;
            tokens = new int[]{100,700,200,300,400,500,1000};
            score = s.BagOfTokensScore(tokens, p);
            Console.WriteLine($"Result: {score} - Expect: {0}");

            p = 350;
            tokens = new int[]{100,700,200,300,400,500,1000};
            score = s.BagOfTokensScore(tokens, p);
            Console.WriteLine($"Result: {score} - Expect: {3}");

            Console.WriteLine("Hello World!");
        }
    }
}
