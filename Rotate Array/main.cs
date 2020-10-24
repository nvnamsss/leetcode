/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/

using System;
using System.Collections.Generic;

public class Solution
{
    public void Rotate(int[] nums, int k)
    {
        int[] rs = new int[nums.Length];
        int index = 0;
        for (int loop = nums.Length - (k % nums.Length); loop < nums.Length; loop++)
        {
            rs[index] = nums[loop];
            index++;
        }

        for (int loop = 0; loop < nums.Length - (k % nums.Length); loop++)
        {
            rs[index] = nums[loop];
            index++;
        }

        for (int loop = 0; loop < nums.Length; loop++)
        {
            nums[loop] = rs[loop];
        }
    }
    
    private void rotate(int[] nums, int from, int to, int k)
    {
        int n = to - from;
        if (n <= 1) return;
        k = k % n;

        for (int loop = 0; loop < k; loop++)
        {
            int symetric = to - k + loop;
            int temp = nums[symetric];
            nums[symetric] = nums[from + loop];
            nums[from + loop]=  temp;
        }

        if (k > 0)
            rotate(nums, from + k, to, k);
    }

    public void Rotate2(int[] nums, int k)
    {
        rotate(nums, 0, nums.Length, k);
    }
}