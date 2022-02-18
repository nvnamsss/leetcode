/*

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int ans = 0;
        vector<vector<int>> merge;
        sort(points.begin(), points.end());
        int lower = points[0][0];
        int upper = points[0][1];
        int i = 0;
        while (i < points.size())
        {
            if ((points[i][0] >= lower && points[i][0] <= upper) || (points[i][1] >= lower && points[i][1] <= upper))
            {
                lower = max(points[i][0], lower);
                upper = min(points[i][1], upper);
            }
            else
            {
                ans++;
                lower = points[i][0];
                upper = points[i][1];
            }

            i++;
        }

        return ans + 1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << s.findMinArrowShots(points) << endl;
}