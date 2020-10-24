/*
All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.
*/

using System;
using System.Text;
using System.Collections.Generic;

public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s) {
        List<string> rs = new List<string>();
        if (s.Length < 10) return rs;

        Dictionary<string, int> dna = new Dictionary<string, int>();
        StringBuilder sb = new StringBuilder();
        sb.Append(s.Substring(0, 10));
        dna.Add(sb.ToString(), 1);
        for (int loop = 10; loop < s.Length; loop++)
        {
            sb.Remove(0, 1);
            sb.Append(s[loop]);
            string d = sb.ToString();
            if (!dna.ContainsKey(d))
                dna.Add(d, 0);
            dna[d]++;
        }

        foreach (var item in dna)
        {
            if (item.Value >= 2) rs.Add(item.Key);
        }

        return rs;
    }
}