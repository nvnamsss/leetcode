/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dpx = vector<vector<int>>(m, vector<int>(n + 1, 0));
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] - '0'){
                    dpx[i][j + 1] = dpx[i][j] + 1;
                }
            }
        }
        
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n; j > 0; j--)
            {
                int k = i;
                int r = 0;
                int c = dpx[k][j];
                while (k >= 0 && dpx[k][j]) {
                    c = min(c, dpx[k][j]);
                    r = r + 1;
                    k--;

                    ans = max(ans, r * c);
                }
            }
            
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
        };
    cout << s.maximalRectangle(matrix) << endl;
}