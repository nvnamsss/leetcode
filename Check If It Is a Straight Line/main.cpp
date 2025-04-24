/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][0];
        for (int i = 2; i < coordinates.size(); i++)
        {
            double x = coordinates[i][0] - coordinates[0][0];
            double y = coordinates[i][1] - coordinates[0][1];

            if (dx * y != dy * x) {
                return false;
            }
        }
        
        
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> coors = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    s.checkStraightLine(coors);

    coors = {{0, 0}, {0, 1}, {0, -1}};
    s.checkStraightLine(coors);

    coors = {{1,1}, {2,2}, {2,0}};
    s.checkStraightLine(coors);
}