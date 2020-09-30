/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/

public class Solution {
    public bool IsMatch(string s, string p) {
        bool[][] dp = new bool[s.Length + 1][];
        for (int loop = 0; loop < s.Length + 1; loop++)
        {
            dp[loop] = new bool[p.Length + 1];
        }

        dp[s.Length][p.Length] = true;

        for (int loop = s.Length; loop >= 0 ; loop--)
        {
            for (int loop2 = p.Length - 1; loop2 >= 0 ; loop2--)
            {
                bool match = loop < s.Length && (s[loop] == p[loop2] || p[loop2] == '?');
                if (loop2 < p.Length && p[loop2] == '*')
                {
                    dp[loop][loop2] = dp[loop][loop2 + 1] || dp[loop + 1][loop2];
                }
                else {
                    dp[loop][loop2] = match && dp[loop + 1][loop2 + 1];
                }
            }
        }

        return dp[0][0];
    }
}