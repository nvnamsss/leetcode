/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {
        {1,0}, {0,1}, {-1, 0}, {0, -1}
    };

    int m;
    int n;

    int recursive(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y) {
        if (dp[x][y] != 0) {
            return dp[x][y];
        }
        
        int ans = 0;

        for (int i = 0; i < directions.size(); i++)
        {
            /* code */
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            if (nx < 0 || ny < 0 || nx == m || ny == n) {
                continue;
            }

            if (matrix[nx][ny] <= matrix[x][y]) continue;

            ans = max(ans, recursive(matrix, dp, nx, ny));
        }

        dp[x][y] = ans + 1;
        return dp[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n,0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, recursive(matrix, dp, i, j));
            }
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {9,9,4},{6,6,8},{2,1,1}
    };
    cout << s.longestIncreasingPath(matrix) << endl; 
}