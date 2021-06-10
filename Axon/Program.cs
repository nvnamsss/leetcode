using System;

namespace Axon
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] prices = new double[]{
                5.4, 3.3, 5
            };

            long[] rounded = Challenge.RoundPrices(prices);
            Array.ForEach(rounded, Console.WriteLine);

            Console.WriteLine("Hello World!");
        }
    }
}
