/*
The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 

Example 1:


Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
Example 2:

Input: dungeon = [[0]]
Output: 1
 

Constraints:

m == dungeon.length
n == dungeon[i].length
1 <= m, n <= 200
-1000 <= dungeon[i][j] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int initialize = INT16_MAX;
    vector<vector<int>> dp;
    int m;
    int n;

    int recursive(vector<vector<int>> &dungeon, int r, int c)
    {
        // if (r == m || c == n) return 0;
        if (dp[r][c] != initialize)
        {
            return dp[r][c];
        }

        // int val = -dungeon[r][c];
        if (c + 1 < n)
        {
            int v = recursive(dungeon, r, c + 1);
            int m = max(0, v - dungeon[r][c]);
            dp[r][c] = min(m, dp[r][c]);
        }

        if (r + 1 < m)
        {
            int v = recursive(dungeon, r + 1, c);
            int m = max(0, v - dungeon[r][c]);
            dp[r][c] = min(m, dp[r][c]);
        }

        cout << "dp[" << r << "][" << c << "] = " << dp[r][c] << endl;
        return dp[r][c];
    }

public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, initialize));
        dp[m - 1][n - 1] = max(0, -dungeon[m - 1][n - 1]);
        return 1 + recursive(dungeon, 0, 0);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> dungeon = vector<vector<int>>{
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}};

    int rs = s.calculateMinimumHP(dungeon);
    cout << "result: " << rs << endl;

    dungeon = vector<vector<int>>{
        {1}};

    rs = s.calculateMinimumHP(dungeon);
    cout << "result: " << rs << endl;

    return 0;
}