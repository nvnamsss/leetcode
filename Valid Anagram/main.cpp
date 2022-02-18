/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        map<char, int> m;
        for (int loop = 0; loop < s.size(); loop++)
        {
            char c = s[loop];
            if (m.find(c) == m.end())
            {
                m.insert(pair<char, int>(c, 0));
            }

            m[c]++;
        }

        for (int loop = 0; loop < t.size(); loop++)
        {
            char c = t[loop];
            if (m.find(c) == m.end())
                return false;
            m[c]--;
            if (m[c] == 0)
                m.erase(c);
        }

        return true;
    }
};