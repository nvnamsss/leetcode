#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1;
        int dp2 = 2;
        for (int i = 2; i < n; i++)
        {
            if (i % 2 == 0) {
                dp1 = dp1 + dp2;
            } else {
                dp2 = dp1 + dp2;
            }
        }
        
        return n % 2 == 0 ? dp2 : dp1;
    }
};