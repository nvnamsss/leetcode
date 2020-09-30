/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
using System;
using System.Collections.Generic;
public class Solution {
    public int MinDistance(string word1, string word2) {
        int[][] dp = new int[word1.Length + 1][];
        for (int loop = 0; loop <= word1.Length; loop++)
        {
            dp[loop] = new int[word2.Length + 1];
        }
        
        for (int loop = 0; loop < word1.Length; loop++)
        {
            dp[loop][0] = loop;
        }

        for (int loop = 0; loop < word2.Length; loop++)
        {
            dp[0][loop] = loop;
        }

        for (int loop = 1; loop < word1.Length; loop++)
        {
            for (int loop2 = 1; loop2 < word2.Length; loop2++)
            {
                if (word1[loop] == word2[loop2])
                {
                    dp[loop][loop2] = dp[loop - 1][loop2 - 1];
                }
                else {
                    dp[loop][loop2] = 1 + Math.Min(Math.Min(dp[loop - 1][loop2], dp[loop][loop2-1]), dp[loop - 1][loop2 - 1]);
                }
            }
        }

        return dp[word1.Length][word2.Length];
    }
}