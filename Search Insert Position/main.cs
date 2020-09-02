/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/

using System;

public class Solution
{
    private static int BinarySearch(int[] arr, int l, int r, int value)
    {
        if (r >= l)
        {
            int mid = l + (r - l) / 2;

            // If the element is present at the 
            // middle itself 
            if (arr[mid] == value)
                return mid;

            // If element is smaller than mid, then 
            // it can only be present in left subarray 
            if (arr[mid] > value)
                return BinarySearch(arr, l, mid - 1, value);

            // Else the element can only be present 
            // in right subarray 
            return BinarySearch(arr, mid + 1, r, value);
        }

        // We reach here when element is not present 
        // in array 
        return ~l;
    }
    public int SearchInsert(int[] nums, int target)
    {
        int index = BinarySearch(arr, 0, nums.Length -1, target);
        return index > 0 ? index : ~index;
    }
}