using System;

namespace Champagne_Tower
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution=  new Solution();
            int poured = 1;
            int qr = 1;
            int qc = 1;
            double rs = solution.ChampagneTower(poured, qr, qc);
            Console.WriteLine($"Result: {rs} - Expect: {0.0}");

            poured = 2;
            qr = 1;
            qc =1;
            rs = solution.ChampagneTower(poured, qr, qc);
            Console.WriteLine($"Result: {rs} - Expect: {0.5}");

            Console.WriteLine("Hello World!");
        }
    }
}
