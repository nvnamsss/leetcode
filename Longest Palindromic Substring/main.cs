/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
using System;
public class Solution
{
    private int expandAroundCenter(string s, int l, int r)
    {
        while (l >= 0 && r < s.Length && s[l] == s[r])
        {
            l--;
            r++;
        }

        return r - l - 1;
    }

    public string LongestPalindrome(string s)
    {
        if (s == string.Empty) return string.Empty;
        int start = 0;
        int end = 0;
        for (int loop = 0; loop < s.Length; loop++)
        {
            int l1 = expandAroundCenter(s, loop, loop);
            int l2 = expandAroundCenter(s, loop, loop + 1);
            int l = Math.Max(l1, l2);

            if (l > end - start)
            {
                end = loop + l / 2;
                start = loop - (l - 1) / 2;
            }
        }

        string rs = s.Substring(start, end - start + 1);
        return rs;
    }
}