/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

using System;
public class Solution {
    public string AddBinary(string a, string b) {
        string aa = a;
        string bb = b;
        string result = string.Empty;
            if (aa.Length > bb.Length)
                bb = new string('0', aa.Length - bb.Length) + bb;
            else
                aa = new string('0', bb.Length - aa.Length) + aa;

int r = 0;
            for (int loop = aa.Length - 1; loop >= 0; loop--)
            {
                int va = aa[loop] - 48;
                int vb = bb[loop] - 48;

                result = (va + vb + r) % 2 + result;
                r = (va + vb + r) / 2;
            }
            if (r > 0) result = r + result;     
        return result;
    }
}