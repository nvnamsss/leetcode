/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int get(vector<vector<int>> triangle, int r, int c) {
        if (r < 0 || r >= triangle.size() || c < 0 || c >= triangle[r].size()) {
            return 0;
        }

        return triangle[r][c];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); i++)
        {
            dp.push_back(vector<int>(triangle[i].size(), 0));
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j] = min(get(dp, i - 1, j - 1), get(dp, i - 1, j)) + triangle[i][j];
            }
        }
        
        int last = triangle.size();
        int ans = INT16_MAX;
        for (int i = 0; i < triangle[last - 1].size(); i++)
        {
            ans = min(ans, triangle[last - 1][i]);
        }
        return ans;
        
    }
};