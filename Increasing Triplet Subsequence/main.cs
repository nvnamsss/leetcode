/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
*/

using System;

public class Solution {
    public bool IncreasingTriplet(int[] nums) {
        int first = int.MaxValue;
        int second = int.MaxValue;  
        for (int loop = 0; loop < nums.Length; loop++)
        {
            if (nums[loop] <= first) {
                first = nums[loop];
            } else if (nums[loop] <= second) {
                second = nums[loop];
            } else {
                return true;
            }
        }       
        return false;
    }

    public bool IncreasingNth(int[] nums, int n) {
        int[] nth = new int[n];
        for (int loop = 0; loop < n; loop++)
        {
            nth[loop] = int.MaxValue;
        }

        for (int loop = 0; loop < nums.Length; loop++)
        {
            bool set = false;
            for (int loop2 = 0; loop2 < n; loop2++)
            {
                if (nums[loop] <= nth[loop2]) {
                    nth[loop2] = nums[loop];
                    set = true;
                    break;
                }
            }

            if (!set) return true;
        }

        return false;
    }
}