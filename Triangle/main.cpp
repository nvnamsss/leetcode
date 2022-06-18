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

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp = vector<vector<int>>(1, vector<int>(1));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++)
        {
            dp.push_back(vector<int>(i + 1, 0));
            for (int j = 0; j < triangle[i].size(); j++)
            {
                bool assigned = false;
                if (j-1 >= 0 && j-1 < triangle.size()) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                    assigned = true;
                }

                if (j >= 0 && j < i) {
                    if (!assigned) {
                        dp[i][j] = dp[i-1][j] + triangle[i][j];
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + triangle[i][j]);
                    }
                }
            }
        }

        int last = triangle.size();
        int ans = INT16_MAX;
        for (int i = 0; i < dp[last - 1].size(); i++)
        {
            ans = min(ans, dp[last - 1][i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << s.minimumTotal(triangle) << endl;
}
