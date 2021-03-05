/*
Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.

 

Example 1:

Input: stones = [5,3,1,4,2]
Output: 6
Explanation: 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
Example 2:

Input: stones = [7,90,5,1,100,10,10,2]
Output: 122
 

Constraints:

n == stones.length
2 <= n <= 1000
1 <= stones[i] <= 1000
*/

using System;
using System.Collections.Generic;

public class Solution
{
    public int StoneGameVII(int[] stones)
    {
        /*
            We need to memorize the sum first, then we will apply DP to solve this problem
            we already calculate the total point when stones from kth are removed we denote it as sum
            dp[i1][i2] represent the difference point when we remove the nth stone
            during the loop, we memoize the difference point when abitrary stones are removed we denote it dp      
            we loop over 2 times to simulate the game, in there we make a move and find the max if a player choose stone loop2 or index

        */
        int[] sum = new int[stones.Length + 1];
        int[][] dp = new int[stones.Length][];
        for (int loop = 0; loop < stones.Length; loop++)
        {
            sum[loop + 1] = sum[loop] + stones[loop];
            dp[loop] = new int[stones.Length];
        }

        for (int loop = 2; loop <= stones.Length; loop++)
        {   
            for (int loop2 = 0; loop2 <= stones.Length - loop; loop2++)
            {
                int index = loop2 + loop - 1;
                dp[loop2][index] = Math.Max(sum[index + 1] - sum[loop2 + 1] - dp[loop2 + 1][index], sum[index] - sum[loop2] - dp[loop2][index - 1]);
            }
        }

        return dp[0][stones.Length - 1];
    }
}