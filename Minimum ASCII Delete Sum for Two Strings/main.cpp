/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.



Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.


Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int maxOfLCS(string s1, string s2)
    {
        int sum = 0;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 0; i <n; i++)
        {
            sum += (s1[i] + 'a');
        }

        for (int i = 0; i < m; i++)
        {
            sum += (s2[i] + 'a');
        }

        for (int i = 0; i < n; i++)
        {
            int costi = s1[i] + 'a';
            for (int j = 0; j < m; j++)
            {
                if (s1[i] == s2[j])
                {
                    dp[i+1][j+1] = dp[i][j] + costi;
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
                
            }
        }
        cout << sum << endl;
        return sum - dp[n][m] * 2;
    }

public:
    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1));
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    int cost1 = dp[i + 1][j] + (s1[i] + 'a');
                    int cost2 = dp[i][j + 1] + (s2[j] + 'a');
                    int cost3 = dp[i + 1][j + 1] + (s1[i] + 'a') + (s2[j] + 'a');
                    dp[i][j] = min(cost1, min(cost2, cost3));
                }
            }
        }

        return dp[0][0];
    }
};