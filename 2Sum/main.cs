/*
Given an array of integers nums and an integer target
 return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

using System;
using System.Collections.Generic;

public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> map = new Dictionary<int, int>();
        for (int loop = 0; loop < nums.Length; loop++)
        {
            if (!map.ContainsKey(nums[loop]))
            {
                map.Add(nums[loop], loop);
            }

            int complement = target - nums[loop];
            if (map.ContainsKey(complement))
            {
                return new int[]{map[nums[loop]], map[complement]};
            }
            
        }

        return new int[0] { };
    }
}
