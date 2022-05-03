using System;
public class Solution {
    public int CoinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        for (int loop = 0; loop < dp.Length; loop++)
        {
            dp[loop] = -1;
        }
        dp[0] = 0;

        for (int loop = 0; loop < amount; loop++)
        {
            if (dp[loop] == -1) continue;
            for (int loop2 = 0; loop2 < coins.Length; loop2++)
            {
                long v = loop + coins[loop2];
                if (v > amount) continue;
                if (dp[v] == -1) {
                    dp[v] = dp[loop] + 1;
                } else {
                    dp[v] = Math.Min(dp[v], dp[loop] + 1);
                }
            }
        }

        return dp[amount];
    }
}