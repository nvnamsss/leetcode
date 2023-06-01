#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int sum = 0;
        vector<double> times = vector<double>(dist.size());
        for (int i = 0; i < dist.size(); i++)
        {
            sum += dist[i];
            times[i] = dist[i] * 1.0 / speed;
        }
        
        if (sum >= speed * hoursBefore) {
            return -1;
        }
        vector<vector<int>> dp = vector<vector<int>>(dist.size(), vector<int>(dist.size()));
        for (int i = 0; i < dist.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == 0 && j == 0) {
                    dp[i][j] = times[i];
                } else if (i == j) {
                    dp[i][j] = dp[i-1][j-1] + times[i];
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j] + times[i];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + times[i];
                }
            }
            
        }
        
        for (int i = 0; i < dist.size(); i++)
        {
            if (dp[dist.size() - 1][i] <= hoursBefore) {
                return i;
            }
        }
        
        
        return -1;
    }
};