/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int recursive(vector<int> &prices, vector<vector<int>> &dp, int day, int transactionLeft)
    {
        // 3 choices in a day
        // buy
        // sell
        // donothing
        if (day == prices.size() || transactionLeft == 0) {
             return 0;
        }

        if (dp[day][transactionLeft] != -1) {
            return dp[day][transactionLeft];
        }

        int ans1 = recursive(prices, dp, day + 1, transactionLeft);
        int ans2 =0;
        bool buy = transactionLeft % 2 == 0;
        if (buy) {
            ans2 = -prices[day] + recursive(prices, dp, day + 1, transactionLeft - 1);
        } else {
            ans2 = prices[day] + recursive(prices, dp, day + 1, transactionLeft - 1);
        }

        dp[day][transactionLeft] = max(ans1, ans2);
        return dp[day][transactionLeft];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp = vector<vector<int>>(prices.size(), vector<int>(4, -1));
        return recursive(prices, dp, 0, 4);
    }
};