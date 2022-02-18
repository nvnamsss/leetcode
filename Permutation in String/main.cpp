/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size()) return false;
        vector<int> m1 = vector<int>(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            m1[s1[i] - 'a']++;
        }

        vector<int> m2 = vector<int>(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            m2[s2[i] - 'a']++;
        }

        if (match(m1, m2)) return true;

        for (int i = 1; i <= s2.size() - s1.size(); i++)
        {
            m2[s2[i-1] - 'a']--;
            m2[s2[i + s1.size() - 1] - 'a']++;

            if (match(m1, m2)) return true;
        }

        return false;
    }

    bool match(vector<int> m1, vector<int> m2)
    {
        for (int k = 0; k < 26; k++)
        {
            if (m1[k] != m2[k])
                return false;
        }
        return true;
    }
};

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    Solution s;
    cout << s.checkInclusion(s1, s2) << endl;
}