/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

using System;
using System.Collections.Generic;
public class Solution
{
    public bool CanPartition(int[] nums)
    {
        int total = 0;
        for (int loop = 0; loop < nums.Length; loop++)
        {
            total += nums[loop];
        }

        if (total % 2 != 0) return false;
        int subsetSum = total / 2;
        bool[] dp = new bool[subsetSum + 1];
        dp[0] = true;
        for (int loop = 0; loop < nums.Length; loop++)
        {
            for (int loop2 = subsetSum; loop2 >= nums[loop]; loop2--)
            {
                dp[loop2] = dp[loop2] || dp[loop2 - nums[loop]];
            }
        }

        return dp[subsetSum];
    }
}