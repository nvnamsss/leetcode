/*
Given an integer array nums, return the number of longest increasing subsequences.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 

Constraints:

0 <= nums.length <= 2000
-106 <= nums[i] <= 106
*/

using System;
using System.Collections;

public class Solution {
    public int FindNumberOfLIS(int[] nums) {
        int[] dp = new int[nums.Length];
        int[] dpcount = new int[nums.Length];
        for (int loop = 0; loop < nums.Length; loop++)
        {
            // dp[loop] = 1;
            dpcount[loop] = 1;
            for (int loop2 = 0; loop2 < loop; loop2++)
            {
                if (nums[loop] > nums[loop2])
                {
                    if (dp[loop2] >= dp[loop]) {
                        dp[loop] = dp[loop2] + 1;
                        dpcount[loop] = dpcount[loop2];
                    } else if (dp[loop2] + 1 == dp[loop]) {
                        dpcount[loop] += dpcount[loop2];
                    }
                } 
            }
            
        }

        int max = 0;
        int count = 0;
        for (int loop = 0; loop < dp.Length; loop++)
        {
            max = Math.Max(max, dp[loop]);
        }

        for (int loop = 0; loop < dp.Length; loop++)
        {
            if (dp[loop] == max)  count += dpcount[loop];
        }

        return count;
    }
}