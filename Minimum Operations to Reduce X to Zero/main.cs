/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

using System;

public class Solution
{
    public int MinOperations(int[] nums, int x)
    {
        if (nums.Length == 1)
        {
            return nums[0] == x ? 1 : -1;
        }

        int[] dpl = new int[nums.Length];
        int[] dpr = new int[nums.Length];
        dpl[0] = nums[0];
        dpr[nums.Length - 1] = nums[nums.Length - 1];
        for (int loop = 1; loop < nums.Length; loop++)
        {
            dpl[loop] = dpl[loop - 1] + nums[loop];
        }

        for (int loop = nums.Length - 2; loop >= 0; loop--)
        {
            dpr[loop] = dpr[loop + 1] + nums[loop];
        }

        int min = int.MaxValue;
        for (int loop = 0; loop < nums.Length; loop++)
        {
            if (dpl[loop] > x) break;
            if (dpl[loop] == x) min = Math.Min(loop + 1, min);
            else
            {
                int r = nums.Length - 1;
                while (r > loop && dpl[loop] + dpr[r] <= x)
                {
                    if (dpl[loop] + dpr[r] == x) min = Math.Min(loop + 1 + (nums.Length - r), min);
                    r--;
                }
            }
        }

        for (int loop = nums.Length - 1; loop >= 0; loop--)
        {
            if (dpr[loop] > x) break;
            if (dpr[loop] == x) min = Math.Min(nums.Length - loop, min);
            else
            {
                int l = 0;
                while (l < loop && dpr[loop] + dpl[l] <= x)
                {
                    if (dpr[loop] + dpl[l] == x) Math.Min(l + (nums.Length - loop) + 1, min);
                    l++;
                }
            }
        }

        return min == int.MaxValue ? -1 : min;
    }
}