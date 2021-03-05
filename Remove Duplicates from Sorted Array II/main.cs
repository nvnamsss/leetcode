/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer, but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 

Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3]
Explanation: Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively. It doesn't matter what you leave beyond the returned length.
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3]
Explanation: Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively. It doesn't matter what values are set beyond the returned length.
 

Constraints:

0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in ascending order.
*/

using System;

public class Solution {
    public void Print(int[] nums) {
        for (int loop = 0; loop < nums.Length; loop++)
        {
            Console.Write($"{nums[loop]} \t");
        }
        Console.WriteLine();
    }
    private int ShiftLeft(int[] nums, int from, int to) {
        int length = nums.Length - from;

        for (int loop = 0; loop < length; loop++)
        {
            nums[to + loop] = nums[from + loop];
        }

        return from - to;
    }

    public int RemoveDuplicates(int[] nums) {
        // int length = nums.Length;
        // for (int loop = nums.Length - 3; loop >= 0 ; loop--)
        // {
        //     if (nums[loop] == nums[loop + 2]) {
        //         int window = 1;
        //         while (loop - window >= 0 && nums[loop - window] == nums[loop + 2]) window++;
        //         int shift = ShiftLeft(nums, loop + 1, loop - (window - 1));
        //         length -= shift;
        //         loop -= shift;
        //     }
        // }

        // return length;   

        int slow = 2;
        int fast = 2;
        while (fast < nums.Length) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }  
            fast++;          
        }
        return nums.Length < 2 ? nums.Length : slow;
    }

    
}