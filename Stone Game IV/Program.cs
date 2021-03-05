using System;

namespace Stone_Game_IV
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int n = 1;
            bool rs = s.WinnerSquareGame(n);
            Console.WriteLine($"Case: {n} - Result: {rs} - Expect: {true}");

            n = 2;
            rs = s.WinnerSquareGame(n);
            Console.WriteLine($"Case: {n} - Result: {rs} - Expect: {false}");

            n = 4;
            rs = s.WinnerSquareGame(n);
            Console.WriteLine($"Case: {n} - Result: {rs} - Expect: {true}");

            n = 5;
            rs = s.WinnerSquareGame(n);
            Console.WriteLine($"Case: {n} - Result: {rs} - Expect: {false}");

                        n = 6;
            rs = s.WinnerSquareGame(n);
            Console.WriteLine($"Case: {n} - Result: {rs} - Expect: {true}");

            n = 7;
            rs = s.WinnerSquareGame(n);
            Console.WriteLine($"Case: {n} - Result: {rs} - Expect: {false}");

            n = 17;
            rs = s.WinnerSquareGame(n);
            Console.WriteLine($"Case: {n} - Result: {rs} - Expect: {false}");

            Console.WriteLine("Hello World!");
        }
    }
}
