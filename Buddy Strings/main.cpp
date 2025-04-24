/*
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.


Constraints:

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size()) {
            return false;
        }
        if (s == goal)
        {
            vector<int> freqs = vector<int>(26);
            for (int i = 0; i < s.size(); i++)
            {
                int index = s[i] - 'a';
                freqs[index]++;
            }
            for (int i = 0; i < freqs.size(); i++)
            {
                if (freqs[i] > 1)
                {
                    return true;
                }
            }

            return false;
        }

        vector<int> diff;
        for (int i = 0; i < goal.size(); i++)
        {
            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
        }


        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};