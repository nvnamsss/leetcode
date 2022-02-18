#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int l1 = 1;
        int l2 = 1;
        int l3 = 1;

        int ans = 1;
        vector<int> dp = vector<int>(n + 1, 0);
        dp[1] = 1;
        for (int i = 1; i < n; i++)
        {
            int l1m2 = dp[l1]*2;
            int l2m3 = dp[l2]*3;
            int l3m5 = dp[l3]*5;
            dp[i + 1] = min(l1m2, min(l2m3, l3m5));
            if (dp[i + 1] == l1m2) {
                l1++;
            }
            if (dp[i + 1] == l2m3) {
                l2++;
            }
            if (dp[i + 1] == l3m5) {
                l3++;
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution s;
    s.nthUglyNumber(10);
}