/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = vector<vector<int>>{{1, 0}, {0, 1}};
    int recursive(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int m, int n, int x, int y) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int ans = 0;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < m && ny < n && obstacleGrid[nx][ny] == 0) {
                ans += recursive(obstacleGrid, dp, m, n, nx, ny);
            }
        }
        
        dp[x][y] = ans;
        return dp[x][y];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] || obstacleGrid[0][0]) {
            return 0;
        }

        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
        dp[m-1][n-1] = 1;

        return recursive(obstacleGrid, dp, m, n, 0 ,0);
    }
};