/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = vector<int>(amount + 1, -1);
        dp[0] = 0;
        for (long i = 0; i < amount; i++)
        {
            if (dp[i] == -1) continue;
            for (int j = 0; j < coins.size(); j++)
            {
                long n = i + coins[j];
                if (n > amount) continue;

                if (dp[n] == -1) {
                    dp[n] = dp[i] + 1;
                } else {
                    dp[n] = min(dp[n], dp[i] + 1);
                }
            }
        }

        return dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> coins = {1,2,5};
    int rs = s.coinChange(coins, 11);
    cout << rs << endl;

    coins = {2};
    rs = s.coinChange(coins, 3);
    cout << rs << endl;

    coins = {1, 2147483647};
    rs = s.coinChange(coins, 2);
    cout << rs << endl;
}