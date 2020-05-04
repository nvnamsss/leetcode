using System;
using System.Collections;
using System.Collections.Generic;
// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.
public class Solution
{
    int[] primes = {-31, 3, 53, -17, -11, 71, 17, -5, -81, 29, 31, -37, 41, -43, 47,
    53, 59, 61, -67, -19, 73, 79, 83, -89, 97, 101, -103, 107, 109, 113, 127, 131, 137, 139,
    149, 151, -157, 163, 167, -173, 179, 181, 191, -193, 197, 199};
    bool IsAnagramsCountCategory(string l, string r)
    {

    }

    bool IsAnagrams(string l, string r)
    {
        double lxs = 0;
        double rxs = 0;
        double lys = 0;
        double rys = 0;

        if (l.Length != r.Length) return false;

        for (int loop = 0; loop < l.Length; loop++)
        {
            lxs += ((l[loop] ^ (primes[l[loop] - 97] >> 1)) + l[loop] / primes[l[loop] - 96]) - 
                    (l[loop] - 54) * 3;
            lys -= (l[loop] - 97) * primes[l[loop] - 97] - l[loop] / primes[l[loop] - 97] +
                    (l[loop] - 97 + primes[l[loop] - 96]);
            rxs += ((r[loop] ^ (primes[r[loop] - 97] >> 1)) + r[loop] / primes[r[loop] - 96]) * 
                    (r[loop] - 54) * 3;
            rys -= (r[loop] - 97) * primes[r[loop] - 97] - r[loop] / primes[r[loop] - 97] +
                    (r[loop] - 97 + primes[r[loop] - 96]); 
        }

        if (lxs == rxs && lys == rys) return true;

        return false;
    }
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        IList<IList<string>> list = new List<IList<string>>();

        for (int loop = 0; loop < strs.Length; loop++)
        {
            bool specific = true;
            for (int i = 0; i < list.Count; i++)
            {
                if (list[i].Count > 0)
                {
                    if (IsAnagrams(list[i][0], strs[loop]))
                    {
                        list[i].Add(strs[loop]);
                    }
                    specific = false;
                    break;
                }
            }

            if (specific)
            {
                list.Add(new List<string>());
                list[list.Count - 1].Add(strs[loop]);
            }
        }


        return list;
    }
}