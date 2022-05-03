/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.

 

Example 1:


Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:


Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Constraints:

1 <= points.length <= 500
points[i].length == 2
0 <= xi, yi <= 4 * 104
All the given points are unique.
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT32_MAX;
        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < points.size(); i++)
        {
            m[points[i][0]].insert(points[i][1]);
        }
        
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x1 != x2 && y1 != y2) {
                    if (m[x2].find(y1) != m[x2].end() && m[x1].find(y2) != m[x1].end()) {
                        int area = abs((x1-x2) * (y1-y2));
                        ans = min(ans, area);
                    }
                }
            }
        }
        
        return ans == INT32_MAX ? 0 : ans;
    }
};