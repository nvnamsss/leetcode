using System;

namespace Increasing_Triplet_Subsequence
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] arr = new int[]{1, 2,3,4,5};
            bool result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {true}");

            arr = new int[]{5,4,3,2,1};
            result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {false}");

            arr = new int[]{2,1,5,0,4,6};
            result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {true}");

            arr = new int[]{2,1,5,0,-1,6};
            result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {true}");


            arr = new int[]{2,1,5,0,7,6};
            result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {true}");

            arr = new int[]{2,1,2,1,2,1};
            result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {false}");

            arr = new int[]{1,2,1,2,1,1};
            result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {false}");

            arr = new int[]{1,2,1,2,1,2};
            result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {false}");

            arr = new int[]{2, 4, -1, 7, 7};
                        result = s.IncreasingTriplet(arr);
            Console.WriteLine($"Result: {result} - Expect: {true}");
        }
    }
}
