/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rs = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++)
        {
            dp[i] = vector<int>(n);
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0) continue;
                dp[i][j] = j > 0 ? dp[i][j - 1] + 1 : 1;
                
                int level = dp[i][j];
                for (int loop = 0; loop < level; loop++)
                {
                    if (i - loop < 0) break;
                    level = min(level, dp[i - loop][j]);
                    if (dp[i - loop][j] < loop + 1) break;
                    rs++;
                }
            }
        }
        
        return rs;
    }
};