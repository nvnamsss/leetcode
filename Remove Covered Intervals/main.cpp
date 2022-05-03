#include <bits/stdc++.h>
using namespace std;


struct less_than_key
{
    inline bool operator() (const vector<int>& v1, const vector<int>& v2)
    {
        if (v1[0] == v2[0]) return v12[1] < v1[1];
        return v1[0] < v2[0];
    }
};

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), less_than_key());
        int j = 0;
        int ans = intervals.size();
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {
                ans--;
            } else {
                j = i;
            }
        }

        return ans;   
    }
};