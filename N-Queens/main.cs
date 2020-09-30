/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

using System;
using System.Collections.Generic;
public class Solution {
    IList<IList<string>> rs;
    int n;
    private void setseal(bool[][] banned, int row, int column, bool seal)
    {
        for (int loop = 0; loop < column; loop++)
        {
            banned[row][loop] = seal;
        }

        for (int loop = 0; loop < row; loop++)
        {
            banned[loop][column] = seal;
        }

        int ld = 0;
  
        bool did = false;

        while (did)
        {
            did = false;
            if (row - ld >= 0 && column - ld >= 0)
            {
                banned[row - ld][column - ld] = seal;
                did = true;
            }

            if (row + ld < n && column + ld < n)
            {
                banned[row + ld][column + ld] = seal;
                did = true;
            }

            if (row - ld >= 0 && column + ld < n)
            {
                banned[row - ld][column + ld] = seal;
                did = true;
            }

            if (row + ld < n && column - ld >= 0)
            {
                banned[row + ld][column - ld] = seal;
                did = true;
            }
        }

    }

    private List<string> tomatrix(List<int> rs)
    {
        List<string> rs = string.Empty;
        for (int loop = 0; loop < n; loop++)
        {
            string added = new string('.', n);
            added[rs[loop]] = 'Q';
            rs.Add(added);
        }

        return rs;
    }

    private void backtrack(List<int> rs, bool[][] banned, int column)
    {
        if (column == n)
        {
            rs.Add(tomatrix(rs));
            return;
        }
        
        for (int loop = 0; loop < n; loop++)
        {
            if (!banned[loop][column])
            {
                rs[loop] = column;
                setseal(banned, loop, column, true);
                backtrack(rs, banned, column + 1);
                setseal(banned, loop, column, false);
            }
        }
    }   

    public IList<IList<string>> SolveNQueens(int n) {
        this.n = n;
        rs = new List<IList<string>>();
        bool[][] banned = new bool[n][];
        for (int loop = 0; loop < n; loop++)
        {
            banned[loop] = new bool[n];
        }

        List<int> arr = new List<int>();
        for (int loop = 0; loop < n; loop++)
        {
            arr.Add(-1);
        }
        
        backtrack(arr, banned, 0);

        return result;
    }
}