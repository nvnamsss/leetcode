#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
            return n;
        int dp1 = 0;
        int dp2 = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans = dp1 + dp2;
            dp1 = dp2;
            dp2 = ans;
        }
        return ans;
    }
};