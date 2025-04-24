/*
A split of an integer array is good if:

The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,1,1]
Output: 1
Explanation: The only good way to split nums is [1] [1] [1].
Example 2:

Input: nums = [1,2,2,2,5,0]
Output: 3
Explanation: There are three good ways of splitting nums:
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
Example 3:

Input: nums = [3,2,1]
Output: 0
Explanation: There is no good way to split nums.
 

Constraints:

3 <= nums.length <= 105
0 <= nums[i] <= 104
*/

using System;
public class Solution
{
    public int MODULO = (int)Math.Pow(10, 9) + 7;
    public int WaysToSplit(int[] nums)
    {
        return WaysToSplitK(nums, 3);
    }

    public int WaysToSplitK(int[] nums, int k) {
        int[] dp = new int[nums.Length + 1];
        int[] dpk = new int[k + 2];
        int right = nums.Length - 1;
        int ways = 0;
        dp[0] = 0;
        dpk[0] = 0;
        dpk[1] = 1;
        dpk[k + 1] = nums.Length;

        for (int loop = 0; loop < nums.Length; loop++)
        {
            dp[loop + 1] = dp[loop] + nums[loop];
        }
        
        for (int loop = 2; loop < k; loop++)
        {
            int valL = Range(dp, dpk[loop - 2], dpk[loop - 1]);
            dpk[loop] = BinarySearchL(dp, dpk[loop - 1] + 1, right, valL);
            if (dpk[loop] > nums.Length - loop) return 0;
        }
        dpk[k] = dpk[k - 1] + 1;

        // Print(dpk);
        for (int loop = k; loop >= 1; loop--)
        {
            if (dpk[loop] + 1 == dpk[loop + 1]) continue;
            int last = dpk[loop];
            int l = dpk[loop - 1];
            int r = dpk[loop + 1] ;

            while (l <= r) {
                int m = l + (r - l) / 2;
                int valL = Range(dp, dpk[loop - 1], m);
                int valR = Range(dp, m, dpk[loop + 1]);
                if (valL <= valR) l = m + 1;
                else {
                    r = m - 1;
                } 
            }

            dpk[loop] = Math.Min(dpk[loop + 1] - 1, l);
            ways += dpk[loop] - last + 1;
        }

        return Math.Max(ways, 1);
    }

    public void Print(int[] arr) {
        for (int loop = 0; loop < arr.Length; loop++)
        {
            Console.Write($"{arr[loop]}\t");
        }
        Console.WriteLine();
    }
    public int Range(int[] dp, int from, int to) {
        return dp[to] - dp[from];
    }
    public int BinarySearchL(int[] dp, int left, int right, int val)
    {
        if (left <= right)
        {
            int mid = (left + right) / 2;
            int mv = dp[mid] - val;
            if (mv < val) return BinarySearchL(dp, mid + 1, right, val);
            return BinarySearchL(dp, left, mid - 1, val);
        }

        return left;
    }

    public int BinarySearchR(int[] dp, int left, int right, int fleft, int valM, int valR)
    {
        if (left <= right)
        {
            int mid = (left + right) / 2;
            int mvm = valM + dp[mid] - dp[fleft];
            int mvr = valR + dp[right] - dp[mid];
            if (mvm <= mvr) return BinarySearchR(dp, mid + 1, right, fleft, valM, valR);
            return BinarySearchR(dp, left, mid - 1, fleft, valM, valR);
        }

        return left;
    }
}