/*
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
*/

using System;
using System.Collections.Generic;
public class Solution {
    public char FindTheDifference(string s, string t) {
        Dictionary<char, int> d = new Dictionary<char, int>();
        for (int loop = 0; loop < s.Length; loop++)
        {
            if (!d.ContainsKey(s[loop])) d.Add(s[loop], 0);
            d[s[loop]]++;
        }

        for (int loop = 0; loop < t.Length; loop++)
        {
            if (!d.ContainsKey(t[loop])) return t[loop];

            d[t[loop]]--;
            if (d[t[loop]] == -1) return t[loop];
        }

        return ' ';
    }
}