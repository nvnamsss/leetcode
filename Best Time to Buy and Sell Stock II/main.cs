// Say you have an array prices for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
//              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Example 2:

// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.


// Constraints:

// 1 <= prices.length <= 3 * 10 ^ 4
// 0 <= prices[i] <= 10 ^ 4

public class Solution
{
    int buyPrice;
    int sellPrice;
    int buyAt;
    int sellAt;
    int profit;

    private void transactions()
    {
        if (sellAt < buyAt || buyAt == -1 || sellAt == -1) return;

        profit += sellPrice - buyPrice;
        buyAt = -1;
        sellAt = -1;
    }

    private bool setBuy(int at, int price)
    {
        if (buyAt == -1 || buyPrice > price)
        {
            Console.WriteLine("B: " + price + "..." + at);
            buyPrice = price;
            buyAt = at;
            return true;
        }

        return false;
    }

    private bool setSell(int at, int price)
    {
        if ((sellAt == -1 || sellPrice < price) && price > buyPrice)
        {
            Console.WriteLine("S: " + price + "..." + at);
            sellPrice = price;
            sellAt = at;
            return true;
        }

        return false;
    }

    public int MaxProfit(int[] prices)
    {
        if (prices.Length < 2) return 0;

        buyPrice = prices[0];
        sellPrice = 0;
        buyAt = -1;
        sellAt = -1;
        profit = 0;

        for (int loop = 0; loop < prices.Length; loop++)
        {

            if (setBuy(loop, prices[loop])) continue;

            setSell(loop, prices[loop]);

            if (loop + 1 == prices.Length || prices[loop + 1] < sellPrice)
            {
                transactions();
            }

        }

        return profit;
    }
}