using System;

namespace BinaryGap
{
    class Program
    {
        static void Main(string[] args)
        {   
            Solution s = new Solution();
            int rs = s.solution(32);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            rs = s.solution(9);
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            rs = s.solution(1041);
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            rs = s.solution(15);
            Console.WriteLine($"Result: {rs} - Expect: {0}");
        }
    }
}
