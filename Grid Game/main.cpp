/*
ou are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

 

Example 1:


Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
Example 2:


Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.
Example 3:


Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
 

Constraints:

grid.length == 2
n == grid[r].length
1 <= n <= 5 * 104
1 <= grid[r][c] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // int sum = 0;
        vector<vector<long>> dp = vector<vector<long>>(m, vector<long>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j + 1] = dp[i][j] + grid[i][j];
                // sum += grid[i][j];
            }
        }

        // int max_column = 0;
        // int optimal = 0;
        long ans = -1;
        for (int i = 0; i < n; i++)
        {
            long t = dp[0][i + 1] + (dp[1][n] - dp[1][i]);
            // cout << dp[0][i + 1] << " - " << dp[1][n] - dp[1][i] << endl;

            long temp = max(dp[0][n] - dp[0][i + 1], dp[1][i]);
            if (ans == -1)
            {
                ans = temp;
            }
            else
            {
                ans = min(ans, temp);
            }
            // if (t >= optimal) {
            //     max_column = i;
            //     optimal = t;

            //     ans =

            // }
        }
        // cout << "max column: " << max_column << endl;
        // cout << "the final result: " << dp[0][n] - dp[0][max_column + 1] << " - " << dp[1][max_column] << endl;
        // ans = max(dp[0][n] - dp[0][max_column + 1], dp[1][max_column]);
        return ans;
    }
};  

int main()
{
    Solution s;
    vector<vector<int>> grid = vector<vector<int>>{
        {2, 5, 4},
        {1, 5, 1}};
    int rs = s.gridGame(grid);
    cout << "result: " << rs << endl;
    grid = vector<vector<int>>{
        {3, 3, 1},
        {8, 5, 2}};
    rs = s.gridGame(grid);
    cout << "result: " << rs << endl;

    grid = vector<vector<int>>{
        {1, 3, 1, 15},
        {1, 3, 3, 1}};
    rs = s.gridGame(grid);
    cout << "result: " << rs << endl;

    grid = vector<vector<int>>{
        {20, 3, 20, 17, 2, 12, 15, 17, 4, 15},
        {20, 10, 13, 14, 15, 5, 2, 3, 14, 3}};
    rs = s.gridGame(grid);
    cout << "result: " << rs << endl;

    return 0;
}