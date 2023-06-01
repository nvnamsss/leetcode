#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size() - 1;
        int score = 0;
        int ans = 0;
        while (l <= r)
        {
            if (power >= tokens[l])
            {
                power -= tokens[l];
                l++;
                score += 1;
            }
            else if (score >= 1)
            {
                power += tokens[r];
                score -= 1;
                r--;
            }
            else
            {
                r--;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};