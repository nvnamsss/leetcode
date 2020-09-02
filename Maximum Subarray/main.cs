using System;
public class Solution {
    private int maxSubArray(int[] nums, int low, int high) {
        int lmax = int.MinValue;
        int rmax = int.MinValue;    

        int mid = low + (high - low) / 2;

        if (high == low) return nums[low];
        int sum = 0;
        for (int loop = mid; loop >= low; loop--)
        {
            sum += nums[loop];
            if (sum > lmax) lmax = sum;
        }

        sum = 0;
        for (int loop = mid + 1; loop <= high; loop++)
        {
            sum += nums[loop];
            if (sum > rmax) rmax = sum;
        }

        int descendantMax =  Math.Max(maxSubArray(nums, low, mid), maxSubArray(nums, mid + 1, high));

        return Math.Max(descendantMax, lmax + rmax);
    }
    public int MaxSubArray(int[] nums) {
        return maxSubArray(nums, 0, nums.Length - 1);
    }
}