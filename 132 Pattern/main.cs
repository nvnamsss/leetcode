/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 104
-109 <= nums[i] <= 109
*/

using System;
using System.Collections.Generic;

public class Solution
{
    private int kind(int[] nums)
    {
        return nums[0] < nums[1] ? 0 : -1;
    }

    private bool powder(int[] nums)
    {
        return nums[2] > nums[0] && nums[2] < nums[1];
    }

    public bool Find132pattern(int[] nums)
    {
        if (nums.Length < 3) return false;
        Stack<int> s = new Stack<int>();
        int[] min = new int[nums.Length];
        min[0] = nums[0];
        for (int loop = 1; loop < nums.Length; loop++)
        {
            min[loop] = Math.Min(min[loop - 1], nums[loop]);
        }

        for (int loop = nums.Length - 1; loop >= 0; loop--)
        {
            if (nums[loop] > min[loop])
            {
                while (s.Count > 0 && s.Peek() <= min[loop])
                    s.Pop();
                
                if (s.Count > 0 && s.Peek() < nums[loop]) return true;
                
                s.Push(nums[loop]);
            }    
        }

        return false;

        for (int loop = 1; loop < nums.Length; loop++)
        {
            if (nums[loop] > nums[loop - 1])
            {
                int index = loop - 1;
                // dp[loop] = loop - 1;
                while (dp[index] != -1)
                {
                    index = dp[index];
                }
                dp[loop] = index;

                // if (nums[dpl] < nums[loop - 1]) dpl = loop - 1;
            }
            else {
                dp[loop] = dp[loop - 1];
                if (dp[loop - 1] != -1 && nums[loop] > nums[dp[loop - 1]]) rs = true;
            }
        }

        return rs;
    }
}