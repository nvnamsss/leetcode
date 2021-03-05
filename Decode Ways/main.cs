/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
Example 4:

Input: s = "1"
Output: 1
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

using System;
using System.Collections.Generic;
public class Solution
{
    public int NumDecodings(string s)
    {
        Dictionary<string, int> dictionary = new Dictionary<string, int>();
        for (int loop = s.Length - 1; loop >=0; loop--)
        {
            string sub = s.Substring(loop);
            if (!dictionary.ContainsKey(sub)) {
                if (sub.Length >= 3) {
                    dictionary.Add(sub, decode(dictionary, sub));
                } else {
                    dictionary.Add(sub, d(sub));
                }
            }
        }
        //divide & conquer


        return dictionary[s];
    }
    private int d(string s) {
        if (s.StartsWith('0')) return 0;
        if (s.Length == 1) return 1;
        if (s.Length == 2) {
            int v = int.Parse(s);
            if (v > 26 && v % 10 == 0) return 0;
            if (v > 26) return 1;
            if (v % 10 == 0) return 1;
            return 2;   
        }
        return 0;
    }

    private int decode(Dictionary<string, int> map ,string s)
    {   
        // 3121 => 3 1 2 1, 3 12 1, 3 1 21, 
        
        // 21 => 2 1, 21 
        // 29 => 2 9
        // 129 => 12 9, 1 2 9
        // 2129 => 2 1 2 9, 2 12 9, 21 2 9
        // + case where case is simple
        // 11212 => 8
        // 1212 => 1 2 1 2, 12 12, 1 2 12, 12 1 2, 1 21 2
        // 121 => 1 2 1, 12 1, 1 21
        // 131 => 1 3 1, 13 1
        // 5131 => 5 1 3 1, 5 13 1, 5
        // 1212 will be splitted into
        // 1 2 12
        // thus the result will be (decode(12) - 1) * decode(12) + decode(21)
        // equal to decode(21) + decode(121) = 2 + 3 = 5
        // decode(121) = decode(1) + decode(21)
        // with 11212 => decode(212) + decode(1212) = 3 + 5 = 8
        // decode(1212) = decode(12) + decode(212) = 2 + 3 = 5
        // decode(102) = decode(2) + decode(02)
        // decode(1251312) = decode(51312) + decode(251312) 
        // decode(226) = decode(6) + decode(26)
        // decode(5131) = decode(131) 
        if (s.StartsWith('0')) return 0;

        int v = int.Parse(s.Substring(0, 2));
        string prefix = s.Substring(2);
        string suffix = s.Substring(1);
        if (!map.ContainsKey(prefix)) {
            map.Add(prefix, d(prefix));
        }

        if (!map.ContainsKey(suffix)) {
            if (suffix.Length > 2) {
                map.Add(suffix, decode(map, suffix));
            } else {
                map.Add(suffix, d(suffix));
            }
        }
        
        int v1 = map[prefix];
        int v2 = map[suffix];

        return v <= 26 ? v1 + v2: v2;
        if (s.StartsWith('0')) return 0;

        // if ()
        // int result = 0;
        // int v = int.Parse(s);

        // if (s.Length == 2)
        // {
        //     if (v > 0 && v <= 26)
        //     {
        //         result++;
        //     }
        // }

        // for (int loop = 1; loop <= s.Length - 1; loop++)
        // {
        //     string s1 = s.Substring(0, loop);
        //     string s2 = s.Substring(loop, s.Length - loop);
        //     int br1 = decode(s.Substring(0, loop));
        //     int br2 = decode(s.Substring(loop, s.Length - loop));
        //     result += br1 + br2;
        // }
        // return result;
    }

}