using System;

namespace Product_of_the_Last_K_Numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            ProductOfNumbers p = new ProductOfNumbers();
            int rs;
            p.Add(3);
            p.Add(0);
            rs = p.GetProduct(1);
            Console.WriteLine($"Result: {rs} - Expect: {0}");
            p.Add(2);
            p.Add(5);
            p.Add(4);
            rs = p.GetProduct(2);
            Console.WriteLine($"Result: {rs} - Expect: {20}");
            rs = p.GetProduct(3);
            Console.WriteLine($"Result: {rs} - Expect: {40}");
            rs = p.GetProduct(4);
            Console.WriteLine($"Result: {rs} - Expect: {0}");
            p.Add(8);
            rs = p.GetProduct(2);
            Console.WriteLine($"Result: {rs} - Expect: {32}");
        }
    }
}
