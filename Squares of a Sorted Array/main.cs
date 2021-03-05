/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/

using System;
using System.Collections.Generic;
public class Solution
{
    public void Print(int[] rs)
    {
        for (int loop = 0; loop < rs.Length; loop++)
        {
            Console.Write($"{rs[loop]}\t");
        }
        Console.WriteLine();
    }
    public int[] SortedSquares(int[] nums)
    {
        int[] rs = new int[nums.Length];
        int left = 0;
        int right = nums.Length - 1;
        int index = nums.Length - 1;

        while (left <= right){
            if (Math.Abs(nums[left]) > Math.Abs(nums[right])) {
                rs[index] = nums[left];
                left++;
            } else {
                rs[index] = nums[right];
                right--;
            }   
            rs[index] *= rs[index];
            index--;
        }

        return rs;
        // int[] rs = new int[nums.Length];
        // int startAt = 0;
        // for (int loop = 0; loop < nums.Length; loop++)
        // {
        //     startAt = Math.Abs(nums[loop]) < Math.Abs(nums[startAt]) ? loop : startAt;
        // }

        // int index = 0;
        // int left = startAt;
        // int right = startAt + 1;
        // while (index < nums.Length)
        // {
        //     if (left < 0)
        //     {
        //         rs[index] = nums[right];
        //         right++;
        //     }
        //     else if (right >= nums.Length)
        //     {
        //         rs[index] = nums[left];
        //         left--;
        //     }
        //     else
        //     {
        //         if (Math.Abs(nums[left]) < Math.Abs(nums[right]))
        //         {
        //             rs[index] = nums[left];
        //             left--;
        //         }
        //         else
        //         {
        //             rs[index] = nums[right];
        //             right++;
        //         }
        //     }

        //     rs[index] *= rs[index];
        //     index++;
        // }

        // return rs;
    }

}