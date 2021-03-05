/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

 

Note:

The total number of elements of the given matrix will not exceed 10,000.
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
    public int[] FindDiagonalOrder(int[][] matrix)
    {
        if (matrix.Length == 0) return new int[]{};
        int r = 0;
        int c = 0;
        int m = matrix.Length;
        int n = matrix[0].Length;
        int direction = -1;

        List<int> result = new List<int>();
        while (r + c < m + n - 1)
        {
            //modify here
            int rr = r;
            int cc = c;

            List<int> subset = new List<int>();
            while (rr >= 0 && rr < m && cc >= 0 && cc < n)
            {
                subset.Add(matrix[rr][cc]);
                rr += 1;
                cc -= 1;
            }

            if (direction == 1) {
                for (int loop = 0; loop < subset.Count; loop++)
                {
                    result.Add(subset[loop]);
                }
            } else {
                for (int loop = subset.Count - 1; loop >= 0; loop--)
                {
                    result.Add(subset[loop]);
                }
            }
            
            if (c < n - 1) c++;
            else r++;

            direction *= -1;
        }

        return result.ToArray();
    }

}