/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:
 
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

using System;
using System.Collections.Generic;
public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);

        int l1 = 0;
        int l2 = 1;
        int l3 = 2;
        int min = int.MaxValue;

        for (int loop = 0; loop < nums.Length - 2; loop++)
        {
            int loop2 = loop + 1;
            int loop3 = nums.Length;

            while (loop2 < loop3)
            {
                int sum = nums[loop] + nums[loop2] + nums[loop3];
                if (Math.Abs(sum - target) < Math.Abs(min - target))
                {
                    min = Math.Min(Math.Abs(min - target), Math.Abs(sum - target));
                }

                if (sum < target) loop2++;
                else loop3--;
            }
        }

        return min;
    }
}