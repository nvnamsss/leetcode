/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]
Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is underlined below:
[[-19,57],
 [-40,-5]]
Example 3:

Input: matrix = [[-48]]
Output: -48
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = vector<vector<int>>{
        {1, -1}, {1, 0}, {1,1}
    };
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, INT32_MAX));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < directions.size(); k++)
                {
                    int x = i + directions[k][0];
                    int y = j + directions[k][1];

                    if (y < 0 || y == n) continue;
                    dp[x][y] = min(dp[x][y], dp[i][j] + matrix[x][y]);
                }
            }
        }

        int ans = matrix[m - 1][0];
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, matrix[m-1][i]);
        }
        return ans;
    }
};