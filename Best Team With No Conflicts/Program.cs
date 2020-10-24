using System;

namespace Best_Team_With_No_Conflicts
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] scores = new int[]{1,3,5,10,15};
            int[] ages = new int[]{1,2,3,4,5};
            Solution s = new Solution();

            int rs = s.BestTeamScore(scores, ages);
            Console.WriteLine($"Result: {rs} - Expect: {34}");

            scores = new int[]{4,5,6,5};
            ages = new int[]{2,1,2,1};
            rs = s.BestTeamScore(scores, ages);
            Console.WriteLine($"Result: {rs} - Expect: {16}");

            scores = new int[]{1,2,3,5};
            ages = new int[]{8,9,10,1};
            rs = s.BestTeamScore(scores, ages);
            Console.WriteLine($"Result: {rs} - Expect: {6}");

            Console.WriteLine("Hello World!");
        }
    }
}
