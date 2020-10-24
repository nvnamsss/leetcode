using System;

namespace Rotate_Array
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution= new Solution();
            int[] input = new int[]{1,2,3,4,5,6,7, 8};
            solution.Rotate2(input, 13);
            for (int loop = 0; loop < input.Length; loop++)
            {
                Console.Write($"{input[loop]}\t");
            }
            Console.WriteLine("Hello World!");
        }
    }
}
