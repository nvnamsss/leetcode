/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
        int longestCommonSubsequence(string text1, string text2) {
        int ans = 0;
        vector<vector<int>> dp = vector<vector<int>>(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
            
        }
        
        return dp[text1.size()][text2.size()];
    }
public:
    int minDistance(string word1, string word2) {
        int longest = longestCommonSubsequence(word1, word2);
        // int m = min(word1.size(), word2.size());

        return word1.size() + word2.size() - 2 * longest;
    }
};