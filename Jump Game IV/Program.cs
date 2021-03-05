using System;

namespace Jump_Game_IV
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution= new Solution();
            int[] arr = new int[]{7,6,9,6,9,6,9,7};
            int result = solution.MinJumps(arr);
            Console.WriteLine($"Result: {result} - Expect: {1}");

            arr = new int[]{100,-23,-23,404,100,23,23,23,3,404};
            result = solution.MinJumps(arr);
            Console.WriteLine($"Result: {result} - Expect: {3}");

            arr = new int[]{3, 4, 3, 5, 6, 4};
            result = solution.MinJumps(arr);
            Console.WriteLine($"Result: {result} - Expect: {2}");

            arr =new int[]{7};
            result = solution.MinJumps(arr);
            Console.WriteLine($"Result: {result} - Expect: {0}");

            arr = new int[]{6,1,9};
            result = solution.MinJumps(arr);
            Console.WriteLine($"Result: {result} - Expect: {2}");

            arr = new int[]{11,22,7,7,7,7,7,7,7,22,13};
            result = solution.MinJumps(arr);
            Console.WriteLine($"Result: {result} - Expect: {3}");

            arr = new int[]{68,-94,-44,-18,-1,18,-87,29,-6,-87,-27,37,-57,7,18,
            68,-59,29,7,53,-27,-59,18,-1,18,-18,-59,-1,-18,-84,-20,7,7,-87,-18,-84,-20,-27};
            result = solution.MinJumps(arr);
            Console.WriteLine($"Result: {result} - Expect: {5}");

        }
    }
}
