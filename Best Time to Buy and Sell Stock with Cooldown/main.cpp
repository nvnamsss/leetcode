/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solution1(vector<int> &prices)
    {
        int rest = 0, hold = rest - prices[0], sold = hold + prices[0];
        // only an action a day (cd = 1)
        // hold => sell or rest, sold => rest, rest => buy or rest
        for (int i = 1; i < prices.size(); ++i)
        {
            int preSold = sold;
            sold = hold + prices[i];            // sold[i] = hold[i-1] + prices[i]
            hold = max(hold, rest - prices[i]); // hold[i] = max(hold[i-1], rest[i-1] - prices[i])
            rest = max(rest, preSold);          // rest[i] = max(rest[i-1], sold[i-1])
        }
        return max(sold, rest);
    }
    int solution2(vector<int> &prices)
    {
        int ans = 0;
        int k = 0;
        int i = 1;
        while (i < prices.size()) {
            if (prices[i] < prices[k]) {
                k = i;
            }
            while (i + 1 < prices.size() && prices[i+1] >= prices[i]) {
                i++;
            }

            if (prices[i] > prices[k]) {
                ans += prices[i] - prices[k];
                i++;
            }
            i++;
        }
        return ans;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return solution2(prices);
    }
};

int main() {
    Solution s;
    s.maxProfit()
}