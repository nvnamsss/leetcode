using System;

public class Solution {
    public int MaxProfit(int[] prices) {
        int interest = 0;
        int hold = interest - prices[0];
        int sold = hold + prices[0];
        for (int i = 0; i < prices.Length; i++)
        {
            int preSold = sold;
            sold = hold + prices[i];
            hold = Math.Max(hold, interest - prices[i]);
            interest = Math.Max(interest, preSold);
        }

        return Math.Max(interest, sold);
    }
}