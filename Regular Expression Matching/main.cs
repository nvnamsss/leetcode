/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/
using System;
using System.Collections.Generic;
public class Solution {
    private bool compare(string s, string pattern)
    {
        if (pattern[pattern.Length - 1] != "*")
        {
            if (s.Length != pattern.Length) return false;
            
            return compare(s[0], pattern[0]);
            // return s == pattern;            
        }
        else {
            char c = pattern[0];
            for (int loop = 0; loop < s.Length; loop++)
            {
                if (!compare(s[loop], c)) return false;
            }
            return true;
        }
    }
    private bool compare(char s, char p)
    {
        if (p == '.') return true;
        return s == p;
    }

    public bool IsMatch(string s, string p) {
             bool[][] dp = new bool[s.Length + 1][];
            for (int loop = 0; loop < s.Length + 1; loop++)
            {
                dp[loop] = new bool[p.Length + 1];
            }
            dp[s.Length][p.Length] = true;

            for (int loop = s.Length; loop >= 0; loop--)
            {
                for (int loop2 = p.Length - 1; loop2 >= 0; loop2--)
                {
                    bool first_match = loop < s.Length && (p[loop2] == s[loop] || p[loop2] == '.');
                    if (loop2 + 1 < p.Length && p[loop2 + 1] == '*')
                    {
                        dp[loop][loop2] = dp[loop][loop2 + 2] || first_match && dp[loop + 1][loop2];
                    } 
                    else
                    {
                        dp[loop][loop2] = first_match && dp[loop + 1][loop2 + 1];
                    }
                }
            }

            return dp[0][0];
    }   
}