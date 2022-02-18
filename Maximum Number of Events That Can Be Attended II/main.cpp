/*
You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

 

Example 1:



Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
Example 2:



Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
Example 3:



Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
 

Constraints:

1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        vector<vector<int>> dp = vector<vector<int>>(k, vector<int>(events.size() + 1, 0));
        sort(events.begin(), events.end());
        int n = events.size() - 1;
        for (int i = n; i >= 0; i--)
        {
            dp[0][i] = max(dp[0][i + 1], events[i][2]);
        }

        int ans = dp[0][0];
        for (int i = 1; i < k; i++)
        {
            for (int j = n; j >= 0; j--)
            {

                int l = j + 1;
                int r = n;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if (events[mid][0] > events[j][1])
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }

                dp[i][j] = max(dp[i][j + 1], dp[i - 1][l] + events[j][2]);
                ans = max(dp[i][j], ans);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> events = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3},
        {4, 4, 4}};
    int rs = s.maxValue(events, 3);
    cout << rs << endl;

    events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    rs = s.maxValue(events, 2);
    cout << rs << endl;

    events = {

        {40, 73, 65},
        {57, 79, 80},
        {51, 57, 19},
        {33, 99, 77},
        {47, 85, 44},
        {18, 56, 11},
        {19, 78, 87},
        {23, 80, 37},
        {26, 48, 74},
        {45, 87, 80},
        {10, 12, 52},
        {23, 83, 43},
        {48, 84, 42},
        {23, 39, 3}};
    rs = s.maxValue(events, 13);
    cout << rs << endl;
}