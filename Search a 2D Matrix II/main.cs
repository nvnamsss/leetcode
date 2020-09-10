/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
using System;
using System.Collections.Generic;
public class Solution
{
    public bool SearchMatrix(int[,] matrix, int target)
    {
        int m = matrix.GetLength(0);
        int n = matrix.GetLength(1);

        int rl = 0;
        int rr = m;
        while (rl <= rr)
        {
            int mid = rl + (rr - rl) / 2;
            if (matrix[mid, m - 1] == target)
            {
                rl = mid;
                break;
            }

            if (matrix[mid, m - 1] > target)
                rr = mid - 1;
            else if (matrix[mid, m - 1] < target)
                rl = mid + 1;
        }

        if (rl < rr) return false;

        int cl = 0;
        int cr = 0;
        while (cl <= cr)
        {
            int mid = cl + (cr - cl) / 2;
            if (matrix[rl, mid] == target)
            {
                cl = mid;
                break;
            }

            if (matrix[rl, mid] > target) cr = mid - 1;
            else if (matrix[rl, mid] < target) cl = mid + 1;
        }

        return cl < cr;
    }
}