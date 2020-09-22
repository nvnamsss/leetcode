/*
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/
using System;
using System.Collections.Generic;
public class Solution
{
        bool[][] visited;

    private void dfs(char[][] board, int x, int y)
    {
    }

    public int CountBattleships(char[][] board)
    {
        int m = board.Length;
        int n = board[0].Length;
        visited = new bool[m][];
        int count = 0;
        for (int loop = 0; loop < m; loop++)
        {
            visited[loop] = new bool[n];
        }

        for (int loop = 0; loop < m; loop++)
        {
            for (int loop2 = 0; loop2 < n; loop2++)
            {
                if (visited[loop][loop2]) continue;

                if (board[loop][loop2] == 'X')
                {
                    count += 1;

                    int x = 0;
                    int y = 0;
                    if (loop < m - 1 && board[loop + 1][loop2] == 'X')
                        y = 1;
                    else if (loop2 < n - 1 && board[loop][loop2] == 'X')
                        x = 1;
                    else continue;
                    int r = loop + y;
                    int c = loop2 + x;
                    while (board[r][c] == 'X')
                    {
                        visited[r][c] = true;
                        r += y;
                        c += y;
                    }
                }
            }
        }

        return count;
    }
}