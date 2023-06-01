#include <bits/stdc++.h>
using namespace std;

class Compare {
    public:
    bool operator() (vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] > b[0];
    }
};

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans = 0;
        int minAge = INT32_MAX;
    
        vector<vector<int>> m = vector<vector<int>>(ages.size());
        for (int i = 0; i < ages.size(); i++)
        {
            m[i] = {scores[i], ages[i]};
        }
        
        sort(m.begin(), m.end(), Compare());
        for (int i = 0; i < m.size(); i++)
        {
            if (m[i][1] <= minAge) {
                ans += m[i][0];
                minAge = min(minAge, m[i][1]);
            }
        }
        
        return ans;
    }
};