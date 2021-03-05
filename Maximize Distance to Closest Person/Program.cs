using System;

namespace Maximize_Distance_to_Closest_Person
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] seats = new int[]{1,0,0,0,1,0,1};
            Solution solution= new Solution();
            int rs = solution.MaxDistToClosest(seats);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            seats = new int[]{1,0,0,0};
            rs = solution.MaxDistToClosest(seats);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            seats = new int[]{0, 1};
            rs = solution.MaxDistToClosest(seats);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            seats = new int[]{1, 1, 1, 0, 1};
            rs = solution.MaxDistToClosest(seats);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            seats = new int[]{0, 0, 0, 0, 1};
            rs = solution.MaxDistToClosest(seats);
            Console.WriteLine($"Result: {rs} - Expect: {4}");

                        seats = new int[]{1,0,0,1};
            rs = solution.MaxDistToClosest(seats);
            Console.WriteLine($"Result: {rs} - Expect: {1}");
            Console.WriteLine("Hello World!");
        }
    }
}
