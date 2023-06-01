#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp = vector<bool>(n + 1);
        vector<bool> dp2 = vector<bool>(n + 1);

        dp[0] = true;
        dp[2] = true;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (i % j != 0) {
                    continue;
                }
                int imj = i-j;
                if (!dp[imj]) {
                    dp2[i] = true;
                }

                if (!dp2[imj]) {
                    dp[i] = true;
                }
            }
            
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.divisorGame(2) << endl;
    cout << s.divisorGame(3) << endl;
    cout << s.divisorGame(4) << endl;
}