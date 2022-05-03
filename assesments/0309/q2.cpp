/*
Given an m x n binary matrix mat, return the number of submatrices that have all ones.

 

Example 1:


Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation: 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
Example 2:


Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation: 
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
 

Constraints:

1 <= m, n <= 150
mat[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n + 1, 0));
        for (int i = m - 1; i >=0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (mat[i][j] == 1) {
                    dp[i][j] = dp[i][j + 1] + 1;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int length = dp[i][j];
                for (int k = 1; k <= length; k++)
                {
                    int times = 0;
                    while (i + times < m && dp[i + times][j] >= k) {
                        ans++;
                        times++;
                    }
                }
                
            }
        }
                      
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1,0,1},{1,1,0},{1,1,0}};
    cout << s.numSubmat(mat) << endl;
}