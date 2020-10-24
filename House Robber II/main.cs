/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

using System;
using System.Collections.Generic;

public class Solution {
    private int RobInRange(int[] nums, int from, int to)
    {
        int dp1 = 0;
        int dp2 = 0;
        for (int loop = from; loop < to; loop++)
        {   
            int max = Math.Max(dp2, nums[loop] + dp1);
            dp1 = dp2;
            dp2= max;
        }

        return dp2;
    }

    public int Rob(int[] nums) {
        if (nums.Length == 1) return nums[0];

        int r1 = RobInRange(nums, 0, nums.Length - 1);
        int r2 = RobInRange(nums, 1, nums.Length);
        return Math.Max(r1, r2);
    }
}