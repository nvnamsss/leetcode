using System;

namespace Asteroid_Collision
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = new int[] { 5, 10, -5 };
            Solution solution = new Solution();
            int[] result = solution.AsteroidCollision(input);
            solution.Print(result);

            input = new int[] { 8, -8 };
            result = solution.AsteroidCollision(input);
            solution.Print(result);

            input = new int[] { 10, 2, -5 };
            result = solution.AsteroidCollision(input);
            solution.Print(result);

            input = new int[] { -2, -1, 1, 2 };
            result = solution.AsteroidCollision(input);
            solution.Print(result);
            Console.WriteLine("Hello World!");
        }
    }
}
