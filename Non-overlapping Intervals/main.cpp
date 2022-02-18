/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        int end = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (end > intervals[i][0])
            {
                ans++;
                end = min(end, intervals[i][1]);
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = vector<vector<int>>{
        {-52, 31},
        {-73, -26},
        {82, 97},
        {-65, -11},
        {-62, -49},
        {95, 99},
        {58, 95},
        {-31, 49},
        {66, 98},
        {-63, 2},
        {30, 47},
        {-40, -26},
    };
    int rs = s.eraseOverlapIntervals(intervals);
    cout << rs << endl;
}