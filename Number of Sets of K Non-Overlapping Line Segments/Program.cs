using System;

namespace Number_of_Sets_of_K_Non_Overlapping_Line_Segments
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.NumberOfSets(4, 2);
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            rs = s.NumberOfSets(3, 1);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            
            rs = s.NumberOfSets(30, 7);
            Console.WriteLine($"Result: {rs} - Expect: {796297179}");
            
            rs = s.NumberOfSets(5, 2);
            Console.WriteLine($"Case: ({5}, {2}) - Result: {rs} - Expect: {7}");

            rs = s.NumberOfSets(42, 25);
            Console.WriteLine($"Case: ({42}, {25}) - Result: {rs} - Expect: {630775896}");

            rs = s.NumberOfSets(5, 3);
            Console.WriteLine($"Result: {rs} - Expect: {7}");

            rs = s.NumberOfSets(3, 2);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            rs = s.NumberOfSets(9, 1);
            Console.WriteLine($"Result: {rs} - Expect: {36}");

            rs = s.NumberOfSets(9, 5);
            Console.WriteLine($"Result: {rs} - Expect: {286}");
            
            rs = s.NumberOfSets(5, 4);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            Console.WriteLine("Hello World!");
        }
    }
}
