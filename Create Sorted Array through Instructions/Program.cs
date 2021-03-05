using System;

namespace Create_Sorted_Array_through_Instructions
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution=  new Solution();
            int[] instructions = new int[]{1,5,6,2};
            int cost = solution.CreateSortedArray(instructions);
            Console.WriteLine($"Result: {cost} - Expect: {1}");

            instructions = new int[]{1,3,3,3,2,4,2,1,2};
            cost = solution.CreateSortedArray(instructions);
            Console.WriteLine($"Result: {cost} - Expect: {4}");

            instructions = new int[]{1,2,3,6,5,4};
            cost = solution.CreateSortedArray(instructions);
            Console.WriteLine($"Result: {cost} - Expect: {3}");


            Console.WriteLine("Hello World!");
        }
    }
}
