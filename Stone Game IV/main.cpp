#include <bits/stdc++.h>
using namespace std;    

class Solution {
    bool isPerfectSquare(int v) {
        double squareRoot = sqrt(v);
        float f = floor(squareRoot);
        return f - squareRoot == 0;
    }
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp = vector<bool>(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (isPerfectSquare(i)) {
                dp[i] = true;
                continue;
            }

            int s = 1;
            while (s * s < i) {
                int r = i - s * s;
                if (!dp[r]) {
                    dp[i] = true;
                    break;
                }
                s++;
            }
        }
        
        return dp[n];
    }
};