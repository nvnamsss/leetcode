/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/
using System;
using System.Collections;
using System.Collections.Generic;
public class Solution {
    List<int> arr;
    int rs;
    public bool ValidTriangle(int a, int b, int c)
    {
        if (a + b <= c || a + c <= b || b + c <= a) 
            return false; 
        else
            return true; 
    }
    private void Swap(List<int> l, int a, int b)
    {
        int t = l[a];
        l[a] = l[b];
        l[b] = t;
    }

    private void backtracking(int[] nums, int start)
    {
        if (arr.Count == 3)
        {
            if (ValidTriangle(arr[0], arr[1], arr[2]))
            {
                rs += 1;
            }

            return;
        }

        for (int loop = start; loop < nums.Length; loop++)
        {
            arr.Add(nums[loop]);
            backtracking(nums, start + 1);
            arr.RemoveAt(arr.Count - 1);
        }
    }

    public int TriangleNumber(int[] nums) {
        arr = new List<int>();
        rs = 0;
        if (nums.Length == 0) return rs;
        backtracking(nums, 0);

        return rs;
    }
}