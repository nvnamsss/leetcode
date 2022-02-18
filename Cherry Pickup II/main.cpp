/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 

Example 1:


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
Example 2:


Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
 

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> directions = {1, 0, -1};
    int m;
    int n;

    int dfs(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row, int column1, int column2)
    {
        if (dp[row][column1][column2] != -1) {
            return dp[row][column1][column2];
        }

        int ans = grid[row][column1];
        int optimal = 0;

        if (column1 != column2) {
            ans += grid[row][column2];
        }

        for (int i = 0; i < directions.size(); i++)
        {
            int nrow = row + 1;
            int ncolumn1 = column1 + directions[i];
            if (ncolumn1 < 0 || nrow >= m || ncolumn1 >= n)
            {
                continue;
            }
            for (int j = 0; j < directions.size(); j++)
            {
                int ncolumn2 = column2 + directions[j];
                if (ncolumn2 < 0 || ncolumn2 >= n)
                {
                    continue;
                }
                optimal = max(optimal, dfs(grid, dp, nrow, ncolumn1, ncolumn2));
            }
        }

        dp[row][column1][column2] = ans + optimal;
        return dp[row][column1][column2];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(grid, dp, 0, 0, n - 1);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 0, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 3, 0}, {2, 0, 9, 0, 0, 0, 0}, {0, 3, 0, 5, 4, 0, 0}, {1, 0, 2, 3, 0, 0, 6}};
    int rs = s.cherryPickup(grid);
    cout << rs << endl;
}