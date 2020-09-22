/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

using System;
using System.Collections.Generic;
public class Solution {
    public IList<int> MajorityElement(int[] nums) {
        List<int> result = new List<int>(nums.Length / 3);

        Array.Sort(nums);
        int count = 0;
        int times = (int)Math.Floor(nums.Length / 3.0);
        for (int loop = 0; loop < nums.Length; loop++)
        {
            count = 1;
            while (loop + count < nums.Length && nums[loop] == nums[loop + count])
            {
                count++;
            }

            loop = loop + count - 1;
            if (count > times) result.Add(nums[loop]);
        }

        return result;       
    }
}