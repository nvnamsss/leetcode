using System;

namespace Validate_Stack_Sequences
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] pushed = new int[]{1,2,3,4,5};
            int[] popped = new int[]{4,5,3,2,1};
            bool result = s.ValidateStackSequences(pushed, popped);
            Console.WriteLine($"Result: {result} - Expect: {true}");

            pushed = new int[]{1,2,3,4,5};
            popped = new int[]{4,3,5,1,2};
            result = s.ValidateStackSequences(pushed, popped);
            Console.WriteLine($"Result: {result} - Expect: {false}");

            pushed = new int[]{1,2,3,4,5,6,7};
            popped = new int[]{1,2,5,3,6,7,4};
            result = s.ValidateStackSequences(pushed, popped);
            Console.WriteLine($"Result: {result} - Expect: {false}");
        }
    }
}
