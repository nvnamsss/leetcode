/*
Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
Example 3:

Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Constraints:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist of lowercase letters.
*/
using System;
using System.Collections.Generic;

public class Solution
{
    public bool BuddyStrings(string A, string B)
    {
        if (A.Length != B.Length) return false;
        int[] o = new int[26];

        if (A == B)
        {
            for (int loop = 0; loop < A.Length; loop++)
            {
                o[A[loop] - 'a']++;
            }

            for (int loop = 0; loop < 26; loop++)
            {
                if (o[loop] > 1) return true;
            }
            return false;
        }
        else
        {
            List<int> dif = new List<int>();
            for (int loop = 0; loop < A.Length; loop++)
            {
                if (A[loop] != B[loop]) dif.Add(loop);
            }
            Console.WriteLine(dif.Count);
            return dif.Count == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
        }
    }
}