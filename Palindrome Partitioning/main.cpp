/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void recursive(string s, vector<vector<bool>> &dp, vector<vector<string>> &ans, vector<string>& sub, int at)
    {
        if (at >= s.size())
        {
            ans.push_back(sub);
        }

        for (int i = at; i < s.size(); i++)
        // }
        {
            if (s[at] == s[i] && (i -at <= 2 || dp[at+1][i-1])) {
                dp[at][i] = true;
                sub.push_back(s.substr(at, i - at + 1));
                recursive(s, dp, ans, sub, i + 1);
                sub.pop_back();
            }
        }
        
    }
public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(n, false));
        vector<vector<string>> ans;
        vector<string> sub;
        recursive(s, dp, ans, sub, 0);
        return ans;
    }
};

void print(vector<vector<string>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<vector<string>> ans = s.partition("aaaba");
    print(ans);

    ans = s.partition("aabab");
    print(ans);
}