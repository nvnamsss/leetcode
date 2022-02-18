#include <bits/stdc++.h>
using namespace std;
class Solution {
    int recursive(vector<int>& dp, int n) {
        if (dp[n] != -1) {
            return dp[n];
        }
        int step = (int)sqrt(n);
        int ans = n;
        for (int i = step; i > 0; i--)
        {
            int r = recursive(dp, n - i * i);
            ans = min(ans, 1 + r);
        }
        
        dp[n] = ans;
        return ans;
    }

public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n + 1, -1);
        dp[0] = 0;
        recursive(dp, n);
        return dp[n];
    }
};