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
        List<string> pattern = new List<string>();
        List<string> dp = new List<string>();

        for (int loop = 0; loop < p.Length; loop++)
        {
            if (p[loop] == "*")
                pattern[pattern.Count - 1] += "*";
            else
            {
                pattern.Add(p[loop]);
                dp.Add("");
            }
        }

        int star = 0;
        while ((star = p.IndexOf('*', star) != -1))
        {
            pattern.Add(p[star - 1] + "*");
        }

        int at = 0;
        
        for (int loop = 0; loop < s.Length; loop++)
        {
            dp[at] += s[loop];
            if (compare(dp[at], pattern[at]))
            {
                at++;
            }
            else {
                at--;
                loop--;
            }
        }

        return at == pattern.Count;
    }   
}