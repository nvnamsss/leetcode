/*
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
 

Constraints:

1 <= source.length, target.length <= 1000
source and target consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int search(vector<vector<int>> &dp, int index, int pos)
    {
        int l = 0;
        int r = dp[index].size();
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (dp[index][mid] <= pos)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        // if (l >= dp[index].size()) return -1;
        return dp[index][l];
    }

public:
    int shortestWay(string source, string target)
    {
        vector<vector<int>> dp = vector<vector<int>>(26);
        int pos = -1;
        int npos = 0;
        int ans = 0;
        int ss = source.size();
        for (int i = 0; i < source.size(); i++)
        {
            dp[source[i] - 'a'].push_back(i);
        }
        
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i].push_back(ss);
        }
        
        int i = 0;

        while (i < target.size())
        {
            do
            {
                int index = target[i] - 'a';
                if (dp[index].size() == 1)
                {
                    return -1;
                }

                pos = search(dp, index, pos);
                if (i + 1 < target.size()) {
                    npos = search(dp, target[i + 1] - 'a', pos);
                }
                i++;
            } while (npos < ss && i < target.size());

            pos = -1;
            ans++;
        }

        return ans;
    }

    int shortestWay2(string source, string target)
    {
        vector<vector<int>> idx = vector<vector<int>>(source.size(), vector<int>(26));
        idx[source.size() - 1][source[source.size() - 1] - 'a'] = source.size(); 
        for (int i = source.size() - 2; i >= 0; i--) {
            idx[i] = idx[i + 1];
            idx[i][source[i] - 'a'] = i + 1; 
        }
        int j = 0, res = 1;
        for (int i = 0; i < target.size(); i++) {
            if (j == source.size()) {
                j = 0;
                res++;
            }
            j = idx[j][target[i] - 'a'];
            if (idx[0][target[i] - 'a'] == 0) return -1;
            if (j == 0) {
                res++;
                i--;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.shortestWay2("abc", "cba") << endl;
    cout << s.shortestWay2("abc", "abcbc") << endl;
    cout << s.shortestWay2("abc", "acdbc") << endl;
    cout << s.shortestWay2("xyz", "xzyxz") << endl;
}