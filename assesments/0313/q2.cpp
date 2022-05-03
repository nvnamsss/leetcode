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

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        if (points.size() < 4) {
            return 0;
        }
        unordered_map<pair<int, int>, int> m;
        sort(points.begin(), points.end());
        int ans = 0;    
        int i = 0;
        int x = points[0][0];
        while (i < points.size()) {
            if (points[i][0] == x) {
                
                i++;
            } else {
                x = points[i][0];
            }
        }
        for (int i = 0; i < points.size(); i++)
        {

        }
        
        return ans;
    }
};