using System;

namespace _132_Pattern
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = new int[]{1,2,3,4};
            Solution s = new Solution();
            bool rs  = s.Find132pattern(input);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            input = new int[]{3,1,4,2};
            rs = s.Find132pattern(input);
            Console.WriteLine($"Result: {rs} - Expect: {true}");


            input = new int[]{-1, 3, 2, 0};
            rs = s.Find132pattern(input);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            input = new int[]{1, 0, 3, 6, 2};
            rs = s.Find132pattern(input);
            Console.WriteLine($"Result: {rs} - Expect: {true}");


            input = new int[]{3,5,0,3,4};
            rs = s.Find132pattern(input);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            input = new int[]{1,0,1,-4,-3};
            rs = s.Find132pattern(input);
            Console.WriteLine($"Result: {rs} - Expect: {false}");
             
            Console.WriteLine("Hello World!");  
        }
    }
}
