/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

 

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
 

Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.
*/

using System;
using System.Collections.Generic;
public class Solution
{
    private float Version(string version)
    {
        float v = 0;
        float d = 1;
        string[] split = version.Split('.');
        for (int loop = 0; loop < split.Length; loop++)
        {
            v += int.Parse(split[loop]) * d;
            d *= 0.1f;
        }

        return v;
    }

    public int CompareVersion(string version1, string version2)
    {
        // float v1 = Version(version1);
        // float v2 = Version(version2);

        // if (v1 > v2) return 1;
        // else if (v1 < v2) return -1;

        // return 0;
        string[] s1 = version1.Split('.');
        string[] s2 = version2.Split('.');
        
        if (s1.Length > s2.Length)
        {
            int l = s2.Length;
            Array.Resize(ref s2, s1.Length);
            for (int loop = l; loop < s1.Length; loop++)
            {
                s2[loop] = new string("0");
            }
        }

        if (s1.Length < s2.Length)
        {
            int l = s1.Length;
            Array.Resize(ref s1, s2.Length);
            for (int loop = l; loop < s2.Length; loop++)
            {
                s1[loop] = new string("0");
            }
        }

        for (int loop = 0; loop < s1.Length; loop++)
        {
            int c1 = int.Parse(s1[loop]);
            int c2 = int.Parse(s2[loop]);
            // char c1 = s1[loop].TrimStart('0').PadLeft(1, '0')[0];
            // char c2 = s2[loop].TrimStart('0').PadLeft(1, '0')[0];
            if (c1 < c2) return -1;
            else if (c1 > c2) return 1;
        }

        return 0;
    }
}