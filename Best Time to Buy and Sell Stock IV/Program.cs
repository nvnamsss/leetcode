using System;

namespace Best_Time_to_Buy_and_Sell_Stock_IV
{
    class Program
    {
        static void Main(string[] args)
        {

            int[] prices = new int[]{5,2,3,0,3,5,6,8,1,5};
            int k = 2;
            Solution s = new Solution();
            int profit = s.MaxProfit(k, prices);
            Console.WriteLine($"Best profit: {profit} - expected: {12}");
            
            k = 2;
            prices = new int[]{0,8,5,7,4,7};
            profit = s.MaxProfit(k, prices);
            Console.WriteLine($"Best profit: {profit} - expected: {11}");

            k = 2;
            prices = new int[]{3,4,6,0,3,7,5,8,2,9,1,6,6,2};
            profit = s.MaxProfit(k, prices);
            Console.WriteLine($"Best profit: {profit} - expected: {15}");


            Console.WriteLine("Hello World!");
        }
    }
}
