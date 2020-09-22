/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 400
*/
using System;
using System.Collections.Generic;
//Dynamic programming
public class Solution
{

    private int GetMoney(int[] nums, int index)
    {
        if (index < 0 || index >= nums.Length - 1) return 0;
        return nums[index];
    }

    public int RobConstantSpace(int[] nums)
    {
        int dp1 = 0;
        int dp2 = 0;
        for (int loop = 0; loop < nums.Length; loop++)
        {
            int max = Math.Max(dp2, nums[loop] + dp1);
            dp1 = dp2;
            dp2 = max;
        }
        return dp2;
    }

    public int Rob(int[] nums)
    {
        if (nums.Length == 0) return 0;
        int[] dp = new int[nums.Length];
        int max = int.MinValue;

        for (int loop = 0; loop < nums.Length; loop++)
        {
            if (loop > 2)
            {
                dp[loop] = Math.Max(nums[loop] + dp[loop - 2], nums[loop] + dp[loop - 1]);
            }
            else
            {
                if (loop > 1)
                    dp[loop] = nums[loop] + dp[loop - 2];
                else
                    dp[loop] = nums[loop];
            }
            if (dp[loop] > max) max = dp[loop];
        }

        return max;
    }

    public int RobInRange(int[] nums, int from, int to)
    {
        int dp1 = 0;
        int dp2 = 0;
        for (int loop = from; loop < to; loop++)
        {
            int max = Math.Max(dp2, nums[loop] + dp1);
            dp1 = dp2;
            dp2 = max;
        }
        return dp2;
    }
    public int Rob2(int[] nums)
    {
        if (nums.Length == 1) return nums[0];
        int m1 = RobInRange(nums, 0, nums.Length - 1);
        int m2 = RobInRange(nums, 1, nums.Length);

        return Math.Max(m1, m2);
    }
}