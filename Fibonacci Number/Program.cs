using System;

namespace Fibonacci_Number
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.Fib(2);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            rs = s.Fib(3);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            rs = s.Fib(4);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            rs = s.Fib(10);
            Console.WriteLine($"Result: {rs} - Expect: {55}");

            rs = s.Fib(15);
            Console.WriteLine($"Result: {rs} - Expect: {610}");
            rs = s.Fib(24);
            Console.WriteLine($"Result: {rs} - Expect: {46368}");
            rs = s.Fib(30);
            Console.WriteLine($"Result: {rs} - Expect: {832040}");
        }
    }
}
