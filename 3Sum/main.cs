/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
using System;
using System.Collections.Generic;
public class Solution
{
    public IList<IList<int>> ThreeSum(int[] nums)
    {
        IList<IList<int>> result = new List<IList<int>>();
        if (nums.Length == 0) return result;

        HashSet<KeyValuePair<int, int>> set = new HashSet<KeyValuePair<int, int>>();
        Array.Sort(nums);
        for (int loop = 0; loop < nums.Length - 2; loop++)
        {
            int loop2 = loop + 1;
            int loop3 = nums.Length - 1;
            while (loop2 < loop3)
            {
                if (nums[loop] + nums[loop2] + nums[loop3] > 0) loop3--;
                else if (nums[loop] + nums[loop2] + nums[loop3] < 0) loop2++;
                else
                {
                    if (!set.Contains(new KeyValuePair<int, int>(nums[loop], nums[loop2])))
                    {
                        result.Add(new List<int>() { nums[loop], nums[loop2], nums[loop3] });
                        set.Add(new KeyValuePair<int, int>(nums[loop], nums[loop2]));
                    }
                    loop2++;
                    loop3--;
                }

            }
        }

        return result;
    }
}