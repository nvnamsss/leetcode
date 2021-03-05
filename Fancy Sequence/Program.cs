using System;

namespace Fancy_Sequence
{
    class Program
    {
        static void Main(string[] args)
        {
            Fancy f = new Fancy();
            f.Append(4);
            f.MultAll(2);
            f.AddAll(3);
            int p4 = f.GetIndex(0);
            Console.WriteLine($"Result: {p4} - Expect: {11}");

            f = new Fancy();
            f.Append(2);
            f.AddAll(3);
            f.Append(7);
            f.MultAll(2);
            int p0 = f.GetIndex(0);
            Console.WriteLine($"Result: {p0} - Expect: {10}");
            f.AddAll(3);
            f.Append(10);
            f.MultAll(2);
            p0 = f.GetIndex(0);
            Console.WriteLine($"Result: {p0} - Expect: {26}");
            p0 = f.GetIndex(1);
            Console.WriteLine($"Result: {p0} - Expect: {34}");
            p0= f.GetIndex(2);
            Console.WriteLine($"Result: {p0} - Expect: {20}");

            Console.WriteLine($"{9 * f.PowMod(3, Fancy.MOD - 2, Fancy.MOD) % Fancy.MOD}");
            Console.WriteLine("Hello World!");
        }
    }
}
