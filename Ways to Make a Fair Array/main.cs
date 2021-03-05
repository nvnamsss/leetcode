/*
You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.

 

Example 1:

Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
Example 2:

Input: nums = [1,1,1]
Output: 3
Explanation: You can remove any index and the remaining array is fair.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: You cannot make a fair array after removing any index.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
*/

using System;
using System.Collections.Generic;

public class Solution
{
    private int GetDP(int[] dp, int index)
    {
        if (index < 0 || index >= dp.Length) return 0;
        return dp[index];
    }
    public int WaysToMakeFair(int[] nums)
    {
        if (nums.Length == 1) return 1;
        int way = 0;
        int[] dp = new int[nums.Length];
        dp[nums.Length - 1] = nums[nums.Length - 1];
        dp[nums.Length - 2] = nums[nums.Length - 2];

        for (int loop = nums.Length - 3; loop >= 0; loop--)
        {
            dp[loop] = nums[loop] + dp[loop + 2];
        }

        for (int loop = 0; loop < nums.Length; loop++)
        {
            int even = GetDP(dp, 0) - GetDP(dp, loop + (loop % 2)) + GetDP(dp, loop + 1 + (loop % 2));
            int odd = GetDP(dp, 1) - GetDP(dp, loop + ((loop + 1)  % 2)) + GetDP(dp, loop + 1 + ((loop + 1) % 2));

            if (even == odd) way++;
        }

        return way;
    }
}