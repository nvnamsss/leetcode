using System;

public class Solution {
    public int LengthOfLIS(int[] nums) {
        int[] m = new int[nums.Length + 1];
        int l = 0;
        
        for (int i = 0; i < nums.Length; i++)
        {
            int lo = 1;
            int hi = l;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[m[mid]] < nums[i]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            m[lo] = i;
            if (lo > l) {
                l = lo;
            } 
        } 

        return l;
    }
}