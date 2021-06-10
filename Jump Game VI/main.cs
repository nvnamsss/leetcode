/*
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

 

Example 1:

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
Example 2:

Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
Example 3:

Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0
 

Constraints:

 1 <= nums.length, k <= 105
-104 <= nums[i] <= 104
*/

/*
    explain why we can use greedy by finding the maximum value when nums is less than zero 
    instead of optimize the jump stenps.
    
    we will demonstrate the optimized jump steps will never been the optimized score
    it is a fallacy that we think the ratio between jump step and score - 
    the more jump step, the more score and maybe vice versa.

    in case positive step not found, we only can choose the max negative steps
    we think we have two steps i. j where i, j is not optimized by score but optimized by step
    and q, w, e is optimized by score,
    step is k, 
    if i + j < q + w + e 
    si + sj = n = sq + sw + se
*/
using System;

public class Solution {
    public int MaxResult(int[] nums, int k) {
        int score = nums[nums.Length - 1];
        int index = nums.Length - 1;
        while (index > 0) {
            int at = -1;
            int max = int.MinValue;
            int maxAt = -1;
            int to = Math.Max(0, index - k);
            for (int loop = index - 1; loop >= to; loop--)
            {
                if (nums[loop] >= 0) {
                    score += nums[loop];
                    at = loop;
                    break;
                }else if (nums[loop] >= max || loop == 0) {
                    maxAt = loop;
                    max = nums[loop];
                }

            }

            if (at == -1) {
                index = maxAt;
                score += max;
            } else {
                index = at;
            }
        }

        return score;

        // int[] dp = new int[nums.Length];
        // for (int loop = 1; loop < nums.Length; loop++)
        // {
        //     dp[loop] = dp[loop - 1] + nums[loop];
        //     for (int loop2 = Math.Max(0, loop - k); loop2  < loop - 1; loop2 ++)
        //     {
        //         dp[loop] = Math.Max(dp[loop2] + nums[loop], dp[loop]);
        //     }
        // }

        // return dp[nums.Length - 1];        
    }
}