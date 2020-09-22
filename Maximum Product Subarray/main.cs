/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
using System;
using System.Collections.Generic;
public class Solution {
    int max;
    private int dynamic()
    {
        return 0;
    }

    private void recursive(int[] nums, int start)
    {
        //if (start == nums.Length) return;
        int p = 1;
        // max = Math.Max(p, max);
        for (int loop = start; loop < nums.Length; loop++)
        {
            p *= nums[loop];
            max = Math.Max(p, max);
        }
    }

    private void r(int[] nums, int start)
    {
        if (start == nums.Length - 1) return nums[start];
    }

    private List<int> rr(int[] nums, int start)
    {
        if (start == nums.Length - 1) return new List<int>(1){nums[start]};

        List<int> rn = rr(nums, start + 1);
        List<int> r = new List<int>(1 + rn.Count) {nums[start]};
        for (int loop = 0; loop < rn.Count; loop++)
        {
            r[loop + 1] = rn[loop] * nums[start];
        }

        return r;
    }

    public int MaxProduct(int[] nums) {
        if (nums.Length == 0) return 0;
        int dp1 = 0;
        int dp11 = 0;
        int dp2 = 0;
        int dp22= 0;
        for (int loop = 0; loop < nums.Length; loop++)
        {
            if (nums[loop] > 0)
            {
                dp1 = Math.Max(dp11 * nums[loop], nums[loop]);
                dp2 = Math.Min(dp22 * nums[loop], nums[loop]);
            }   
            else {
                dp1 = Math.Max(dp22 * nums[loop], nums[loop]);
                dp2 = Math.Min(dp11 * nums[loop], nums[loop]);
            }
            dp11 = dp1;
            dp22 = dp2; 
        }
        return Math.Max(dp1, dp11);
    }
}