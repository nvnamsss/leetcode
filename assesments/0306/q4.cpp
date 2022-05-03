/*
You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries. Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. If there is no solution return -1.

 

Example 1:

Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation: 
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).
Example 2:

Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.
 

Constraints:

1 <= colors.length <= 5*10^4
1 <= colors[i] <= 3
1 <= queries.length <= 5*10^4
queries[i].length == 2
0 <= queries[i][0] < colors.length
1 <= queries[i][1] <= 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> dp = vector<vector<int>>(colors.size(), vector<int>(3, colors.size() + 1));
        dp[0][colors[0] - 1] = 0;
        for (int i = 1; i < colors.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = dp[i-1][j] + 1;
            }
            dp[i][colors[i] - 1] = 0;
        }

        dp[colors.size() - 1][colors[colors.size() - 1] - 1] = 0;
        for (int i = colors.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
            }
        }
        

        vector<int> ans = vector<int>(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int index = queries[i][0];
            int color = queries[i][1];
            ans[i] = dp[index][color - 1];
            if (ans[i] > colors.size()) {
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> colors = {1,1,2,1,3,2,2,3,3};
    vector<vector<int>> queries = {{1,3},{2,2},{6,1}};
    vector<int> ans = s.shortestDistanceColor(colors, queries);
}