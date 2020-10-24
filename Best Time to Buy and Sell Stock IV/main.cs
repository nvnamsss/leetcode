/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

0 <= k <= 109
0 <= prices.length <= 104
0 <= prices[i] <= 1000
*/

using System;
using System.Collections.Generic;

public class Solution
{
    public struct Transaction
    {
        public int BuyAt;
        public int SellAt;
        public int BuyPrice;
        public int SellPrice;
        public int Profit => SellPrice - BuyPrice;

        public Transaction(int buy, int sell, int buyPrice, int sellPrice)
        {
            BuyAt = buy;
            SellAt = sell;
            BuyPrice = buyPrice;
            SellPrice = sellPrice;
        }

        public override string ToString()
        {
            return $"{Profit}";
        }
    }

    private int buyAt;
    private int sellAt;
    private int profit;
    private int sellPrice;
    private int buyPrice;
    private int bestProfit;

    private bool buy(int[] prices, int at)
    {
        if (buyAt == -1 || buyPrice > prices[at])
        {
            buyAt = at;
            buyPrice = prices[at];
            return true;
        }
        return false;
    }

    private bool sell(int[] prices, int at)
    {
        if ((sellAt == -1 || sellPrice < prices[at]) && prices[at] > buyPrice)
        {
            sellAt = at;
            sellPrice = prices[at];
            return true;
        }
        return false;
    }

    private void dp(List<Transaction> transactions, int k)
    {
        int kc = 0;
        int total = 0;
        for (int loop = 0; loop < transactions.Count; loop++)
        {


            if (kc == k)
            {
                bestProfit = Math.Max(bestProfit, total);

            }
        }
    }

    private void recursive(List<Transaction> transactions, int start, int total, int kc, int k)
    {
        if (kc == k)
        {
            bestProfit = Math.Max(bestProfit, total);
            return;
        }

        for (int loop = start; loop < transactions.Count; loop++)
        {
            if (start != loop)
            {
                int prof = transactions[loop].SellPrice - transactions[start].BuyPrice;
                recursive(transactions, loop + 1, total + prof, kc + 1, k);
            }
            recursive(transactions, loop + 1, total + transactions[loop].Profit, kc + 1, k);

        }
    }

    public int MaxProfit(int k, int[] prices)
    {
        List<Transaction> transactions = new List<Transaction>();
        sellAt = -1;
        buyAt = -1;
        sellPrice = 0;
        buyPrice = 0;
        bestProfit = int.MinValue;
        //find max profit without k
        //save the milestone where we will save
        //record the time we do the transaction
        //if the transaction is limited, we find the last proficient buy and proficient sell to fit it
        for (int loop = 0; loop < prices.Length; loop++)
        {
            if (buy(prices, loop)) continue;

            sell(prices, loop);
            if (loop + 1 == prices.Length || prices[loop + 1] < sellPrice)
            {
                if (sellAt != -1)
                {
                    transactions.Add(new Transaction(buyAt, sellAt, buyPrice, sellPrice));
                    buyAt = -1;
                    sellAt = -1;
                }

            }
        }

        //then find k best range in the transactions
        while (transactions.Count > k)
        {
            int delete_index = 0;
            int min_delete_loss = int.MaxValue;
            for (int loop = 0; loop < transactions.Count; loop++)
            {
                int profit_loss = transactions[loop].Profit;
                if (profit_loss < min_delete_loss)
                {
                    min_delete_loss = profit_loss;
                    delete_index = loop;
                }
            }

            int merge_index = 0;
            int min_merge_loss = int.MaxValue;
            for (int loop = 1; loop < transactions.Count; loop++)
            {
                int profit_loss = transactions[loop - 1].SellPrice - transactions[loop].BuyPrice;
                if (profit_loss < min_merge_loss)
                {
                    min_merge_loss = profit_loss;
                    merge_index = loop;
                }
            }

            if (min_delete_loss <= min_merge_loss)
            {
                transactions.RemoveAt(delete_index);
            }
            else
            {
                Transaction t = transactions[merge_index - 1];
                t.SellPrice = transactions[merge_index].SellPrice;
                transactions[merge_index - 1] = t;
                transactions.RemoveAt(merge_index);
            }
        }

        // if (transactions.Count > k)
        // {
        //     for (int loop = 0; loop < transactions.Count; loop++)
        //     {
        //         recursive(transactions, loop, 0, 0, k);

        //         // recursive(transactions, loop+1, transactions[loop].Profit, 1, k);

        //     }

        //     // for (int loop = 0; loop < transactions.Count; loop++)
        //     // {
        //     // }
        //     return bestProfit;
        //     //0     3       6 
        //     //2     5       8
        //     //recursive?


        //     // transactions.Sort((a, b) =>
        //     // {
        //     //     return b.Profit.CompareTo(a.Profit);
        //     // });
        // }
        int profit = 0;

        for (int loop = 0; loop < transactions.Count; loop++)
        {
            profit += transactions[loop].Profit;
        }

        return profit;
    }
}