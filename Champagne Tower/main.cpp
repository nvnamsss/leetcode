#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp = vector<vector<double>>(101, vector<double>(101));
        dp[0][0] = poured;
        for (int i = 0; i <= query_row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                double p = (dp[i][j] - 1.0) / 2.0;
                if (p > 0) {
                    dp[i + 1][j] += p;
                    dp[i + 1][j + 1] += p;
                }
            }
            
        }
        
        return min(1.0, dp[query_row][query_glass]);
    }
};