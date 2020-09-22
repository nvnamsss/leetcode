/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
using System;
using System.Collections.Generic;
public class Solution
{

    private void r(int[][] grid, int[][] dp, int r, int c)
    {

    }

    public int MinPathSum(int[][] grid)
    {
        int row = grid.Length;
        int column = grid[0].Length;
        int[][] dp = new int[row][];
        for (int loop = 0; loop < row; loop++)
        {
            dp[loop] = new int[column];
            for (int loop2 = 0; loop2 < column; loop2++)
            {
                dp[loop][loop2] = int.MaxValue;
            }
        }
        
        dp[0][0] = grid[0][0];
        for (int loop = 0; loop < row; loop++)
        {
            for (int loop2 = 0; loop2 < column; loop2++)
            {
                if (loop < row - 1)
                {
                    dp[loop + 1][loop2] = Math.Min(dp[loop][loop2] + grid[loop + 1][loop2], dp[loop + 1][loop2]);
                }

                if (loop2 < column - 1)
                {
                    dp[loop][loop2 + 1] = Math.Min(dp[loop][loop2] + grid[loop][loop2 + 1], dp[loop][loop2 + 1]);
                }
            }
        }

        return dp[row][column];
    }
}