
using System;
using System.Collections.Generic;
public class Solution
{
    int[] nums;
    int[] multipliers;
    int n;
    int m;
    int[][] memo;
    private int recursive(int l, int i) {
        if (i == m) {
            return 0;
        }

        if (memo[l][i] != 0) return memo[l][i];
        int pickLeft = recursive(l + 1, i + 1) + nums[l] * multipliers[i];
        int pickRight = recursive(l, i + 1) + nums[n - (i - l) - 1] * multipliers[i];
        return memo[l][i] = Math.Max(pickLeft, pickRight);
    }

    public int MaximumScore(int[] nums, int[] multipliers)
    {
        m = multipliers.Length;
        n = nums.Length;
        this.nums = nums;
        this.multipliers = multipliers;
        memo = new int[m][];
        for (int loop = 0; loop < m; loop++)
        {   
           memo[loop] = new int[m]; 
        }

        recursive(0, 0);
        return memo[0][0];
    }
}