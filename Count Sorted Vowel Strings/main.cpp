#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int combination(int n, int k)
    {
        int rs = 1;
        for (int loop = 1; loop <= n - k; loop++)
        {
            rs = rs * (k + loop);
            rs = rs / loop;
        }

        return rs;
    }

    int recursive(int n, int k, int c, int l)
    {
        if (l == n)
            return 1;
        int ans = 0;

        for (int i = c; i <= k; i++)
        {
            ans += recursive(n, k, i, l + 1);
        }

        return ans;
    }

    int memoization(int n, int k, int c, int l, vector<vector<int>>& dp) {
        if (dp[l][c] != -1) {
            return dp[l][c];
        }

        int ans = 0;

        for (int i = c; i < k; i++)
        {
            ans += memoization(n, k, i, l + 1, dp);
        }

        dp[l][c] = ans;
        return dp[l][c];
    }

    int mathematic(int n)
    {
        return combination(n + 4, n);
    }

    int computating(int n)
    {
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(5, -1));
        for (int i = 0; i < 5; i++)
        {
            dp[n][i] = 1;
        }
        return memoization(n, 5, 0, 0, dp);
        // return dp[0][0];
        // return recursive(n, 5, 1, 0);
    }

public:
    int countVowelStrings(int n)
    {
        return computating(n);
    }
};

int main()
{
    Solution s;
    cout << s.countVowelStrings(1) << endl;
    cout << s.countVowelStrings(2) << endl;
    cout << s.countVowelStrings(3) << endl;
}