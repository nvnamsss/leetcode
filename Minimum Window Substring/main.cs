/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

using System;
using System.Collections.Generic;

public class Solution
{
    public string MinWindow(string s, string t)
    {
        int l = 0;
        int r = 0;
        int match = 0;
        Dictionary<char, int> h = new Dictionary<char, int>();
        for (int loop = 0; loop < t.Length; loop++)
        {
            if (!h.Contains(t[loop]))
            {
                h.Add(t[loop], 0);
            }
            h[t[loop]] += 1;
        }
        Dictionary<char, int> windowCounts = new Dictionary<char, int>();

        int[] ans = new int[3] { -1, 0, 0 };
        while (r < s.Length)
        {
            //slide left
            char c = s[r];
            if (!windowCounts.ContainsKey(c))
            {
                windowCounts.Add(c, 0);
            }
            windowCounts[c] += 1;

            if (h.ContainsKey(c) && h[c] == windowCounts[c])
            {
                match++;
            }

            while (l <= r && match == h.Count)
            {
                char cc = s[l];
                if (ans[0] == -1 || ans[0] > (r - l + 1))
                {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                windowCounts[cc] -= 1;
                if (h.ContainsKey(cc) && h[cc] < windowCounts[cc])
                {
                    match--;
                }

                l++;
            }

            r++;
        }

        return ans[0] == -1? string.Empty : s.Substring(ans[1], ans[2] - ans[1]);
    }
}