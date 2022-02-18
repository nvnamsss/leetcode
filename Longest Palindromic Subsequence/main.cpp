/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string reverse(string s) {
        string r = "";
        r.resize(s.size());
        int index = s.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {
            r[index] = s[i];
            index--;
        }
        return r;
    }
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp = vector<vector<int>>(s.size() + 1, vector<int>(s.size() + 1));
        string r = reverse(s);
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < r.size(); j++)
            {
                if (s[i] == r[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[s.size()][s.size()];
    }
};