using System;
using System.Collections.Generic;

public class Solution {
    public int LongestCommonSubsequence(string text1, string text2) {
        List<List<int>> dp = new List<List<int>>(text1.Length);
        for (int i = 0; i <= text1.Length; i++)
        {
            dp.Add(new List<int>(new int[text2.Length + 1]));
        }

        for (int i = 0; i < text1.Length; i++)
        {
            for (int j = 0; j < text2.Length; j++)
            {
                if (text1[i] == text2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = Math.Max(dp[i+1][j], dp[i][j+1]);
                } 
            }
        }

        return dp[text1.Length][text2.Length];
    }
}