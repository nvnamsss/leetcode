/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
Example 3:

Input: matrix = [], target = 0
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

using System;
using System.Collections.Generic;
public class Solution
{
    public bool SearchMatrix(int[][] matrix, int target)
    {
        int m = matrix.GetLength(0);
        if (m == 0) return false;
        int n = matrix.GetLength(1);

        List<int> columns = new List<int>();
        for (int loop = 0; loop < n; loop++)
        {
            if (target >= matrix[0][loop] && target <= matrix[m - 1][loop])
            {
                columns.Add(loop);
            }
        }

        for (int loop = 0; loop < columns.Count; loop++)
        {
            int column = columns[loop];
            for (int loop2 = 0; loop2 < m; loop2++)
            {
                if (matrix[loop2][column] == target) return true;
            }
        }

        return false;
    }
}