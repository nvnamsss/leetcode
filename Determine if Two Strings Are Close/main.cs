/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
Example 4:

Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
*/

using System;
using System.Collections.Generic;
using System.Linq;
public class Solution
{
    Dictionary<char, int> d1 = new Dictionary<char, int>();
    Dictionary<char, int> d2 = new Dictionary<char, int>();

    // Find a index set that total of set equal to the totla
    public Dictionary<int, int> NSum(List<int> array)
    {
        Dictionary<int, int> rs = new Dictionary<int, int>();
        rs.Add(0, 0);

        for (int loop = 0; loop < array.Count; loop++)
        {
            Dictionary<int, int> tmp = new Dictionary<int, int>();

            foreach (var item in rs)
            {
                int val = array[loop] + item.Key;
                if (!tmp.ContainsKey(val))
                {
                    tmp.Add(val, 0);
                }
                tmp[val]++;
            }

            foreach (var item in tmp)
            {
                if (!rs.ContainsKey(item.Key))
                {
                    rs.Add(item.Key, 0);
                }
                rs[item.Key]++;
            }
        }

        return rs;
    }

    public bool CloseStrings(string word1, string word2)
    {
        if (word1.Length != word2.Length) return false;

        for (int loop = 0; loop < word1.Length; loop++)
        {
            if (!d1.ContainsKey(word1[loop]))
            {
                d1.Add(word1[loop], 0);
            }
            d1[word1[loop]] += 1;
        }

        for (int loop = 0; loop < word2.Length; loop++)
        {
            if (!d2.ContainsKey(word2[loop]))
            {
                d2.Add(word2[loop], 0);
            }
            d2[word2[loop]] += 1;
        }
        List<int> av = d1.Values.ToArray().ToList();
        List<int> bv = d2.Values.ToArray().ToList();

        av.Sort();
        bv.Sort();

        return d1.Keys.Equals(d2.Keys) && av.Equals(bv);
    }
}