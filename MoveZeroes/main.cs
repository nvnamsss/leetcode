using System;
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:

// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.
public class Solution
{
    private void Swap(int[] nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    public void MoveZeroes(int[] nums)
    {
        int lastNonZeroFoundAt = 0;

        for (int loop = 0; loop < nums.Length; loop++)
        {
            if (nums[loop] != 0)
            {
                nums[lastNonZeroFoundAt++] = nums[loop];
            }

        }

        for (int loop = lastNonZeroFoundAt; loop < nums.Length; loop++)
        {
            nums[loop] = 0;
        }
    }
}