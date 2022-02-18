/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int m;
    int n;
    vector<vector<int>> directions = vector<vector<int>>{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int recursive(vector<vector<int>> &mat, vector<vector<bool>>& visited, vector<vector<int>> &dp, int r, int c)
    {
        if (mat[r][c] == 0) {
            return 0;
        }

        if (dp[r][c] != 0) {
            return dp[r][c];
        }

        int ans = 10e4;
        visited[r][c] = true;
        for (int i = 0; i < directions.size(); i++)
        {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            if (nr < 0 || nr == m || nc < 0 || nc == n || visited[nr][nc]) continue;
            ans = min(recursive(mat, visited, dp, nr, nc) + 1, ans);
        }

        if (dp[r][c] == 0) {
            dp[r][c] = ans;
        } else {
            dp[r][c] = min(dp[r][c], ans);
        }
        return ans;
    }


public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && mat[i][j] == 1) {
                    recursive(mat, visited, dp, i, j);
                } else {
                    dp[i][j] = 0;
                }
            }
            
        }
        
        return dp;
    }
};

int main() {
    vector<vector<int>> mat = vector<vector<int>>{
        {1,0,1,1,0,0,1,0,0,1},
        {0,1,1,0,1,0,1,0,1,1},
        {0,0,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,1,1,1,1,1},
        {0,1,0,1,1,0,0,0,0,1},
        {0,0,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,0,1,1},
        {1,0,0,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,0,1,0},
        {1,1,1,1,0,1,0,0,1,1}
    };
    Solution s;
    s.updateMatrix(mat);
}