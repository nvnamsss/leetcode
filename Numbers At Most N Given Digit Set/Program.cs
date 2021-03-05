using System;

namespace Numbers_At_Most_N_Given_Digit_Set
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            string[] digits = new string[] { "1", "3", "5", "7" };
            int n = 100;
            int rs = s.AtMostNGivenDigitSet(digits, n);
            Console.WriteLine($"Result: {rs} - Expect: {20}");

            digits = new string[] { "1", "4", "9" };
            n = 1000000000;
            rs = s.AtMostNGivenDigitSet(digits, n);
            Console.WriteLine($"Result: {rs} - Expect: {29523}");

            digits = new string[] { "7" };
            n = 8;
            rs = s.AtMostNGivenDigitSet(digits, n);
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            digits = new string[] { "1","3","5","7" };
            n = 64355;
            rs = s.AtMostNGivenDigitSet(digits, n);
            Console.WriteLine($"Result: {rs} - Expect: {1108}");
            

            digits = new string[] { "1","5","7","8" };
            n = 10212;
            rs = s.AtMostNGivenDigitSet(digits, n);
            Console.WriteLine($"Result: {rs} - Expect: {340}");

            Console.WriteLine("Hello World!");
        }
    }
}
