using System;

namespace Maximum_Frequency_Stack
{
    class Program
    {
        static void Main(string[] args)
        {
            FreqStack s = new FreqStack();
            int rs;
            s.Push(5);
            s.Push(7);
            s.Push(5);
            s.Push(7);
            s.Push(4);
            s.Push(5);

            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {5}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {7}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {5}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {4}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {7}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {5}");
            Console.WriteLine("Phase 2");

            s.Push(4);
            s.Push(0);
            s.Push(9);
            s.Push(3);
            s.Push(4);
            s.Push(2);

            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {4}");
            s.Push(6);
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {6}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {2}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {9}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {0}");
            rs = s.Pop();
            Console.WriteLine($"Result: {rs} - Expect: {4}");
        }
    }
}
