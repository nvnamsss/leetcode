/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.



Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4


Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        if (points.size() == 1)
        {
            return 1;
        }
        int ans = 2;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> arcs;

            int ri = points[i][0];
            int ci = points[i][1];
            for (int j = i; j < points.size(); j++)
            {
                if (i == j) {
                    continue;
                }
                int rj = points[j][0];
                int cj = points[j][1];

                int dr = rj - ri;
                int dc = cj - ci;
                double a = atan2(dr, dc);
                arcs[a]++;
            }
            for (auto &&it : arcs)
            {
                ans = max(ans, it.second + 1);
            }
        }

        return ans;
    }
};