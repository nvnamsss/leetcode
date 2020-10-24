/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public string RemoveDuplicateLetters(string s)
    {
        string rs = string.Empty;
        int[] last = new int[26];
        int[] used = new int[26];

        for (int loop = 0; loop < s.Length; loop++)
        {
            last[s[loop]- 'a'] = loop;
        }
        
        for (int loop = 0; loop < s.Length; loop++)
        {
            if (used[s[loop] - 'a']++ > 0) continue;

            while (rs != string.Empty && rs[rs.Length - 1] > s[loop] && loop < last[rs[rs.Length - 1] - 'a'])
            {
                used[rs[rs.Length - 1] - 'a'] = 0;
                rs = rs.Remove(rs.Length - 1, 1);
            }

            rs += s[loop];
        }

        return rs;
    }
}