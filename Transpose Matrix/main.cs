/*
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.



 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 

Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000    
*/

using System;

public class Solution {
    public int[][] Transpose(int[][] A) {
        if (A.Length == 0) return new int[0][];

        int h = A.Length;
        int w = A[0].Length;
        int[][] rs = new int[w][];
        for (int loop = 0; loop < w; loop++)
        {
            rs[loop] = new int[h];
            for (int loop2 = 0; loop2 < h; loop2++)
            {
                rs[loop][loop2] = A[loop2][loop];
            }
        }

        return rs;
    }
}