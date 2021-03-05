/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
using System;
using System.Collections;
public class Solution
{
    public bool Search(int[] nums, int target)
    {
        if (nums.Length == 0) return false;
        if (target <= nums[nums.Length - 1])
        {
            int at = nums.Length - 1;
            while (at >= 0 && target <= nums[at])
            {
                if (target == nums[at]) return true;
                at--;
            }
        }
        else
        {
            int at = 0;
            while (at < nums.Length && target >= nums[at])
            {
                if (target == nums[at]) return true;
                at++;
            }
        }


        return false;
    }
}