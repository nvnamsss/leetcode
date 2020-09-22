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

        List<int> columns = new List<int>();
        for (int loop = 0; loop < n; loop++)
        {
            if (target >= matrix[0, loop] && target <= matrix[m - 1, loop])
            {
                columns.Add(loop);
            }
        }

        for (int loop = 0; loop < columns.Count; loop++)
        {
            int column = columns[loop];
            for (int loop2 = 0; loop2 < m; loop2++)
            {
                if (matrix[loop2, column] == target) return true;
            }
        }

        return false;
    }
}