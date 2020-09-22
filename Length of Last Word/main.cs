/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
using System;
using System.Collections.Generic;
public class Solution {
    public int LengthOfLastWord(string s) {
        string[] split = s.Trim().Split(' ');
        if (split.Length == 0) return 0;
        return split[split.Length - 1].Length;
    }
}