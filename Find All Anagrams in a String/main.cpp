/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> window;
        unordered_map<char, int> pm;
        vector<int> ans;
        int windowCount = 0;

        for (int i = 0; i < p.size(); i++)
        {
            pm[p[i]]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            window[s[i]]++;
            if (pm.find(s[i]) != pm.end() && window[s[i]] <= pm[s[i]]) {
                windowCount++;
            }
            int last = i - p.size();
            if (last >= 0) {
                window[s[last]]--;
                if (window[s[last]] < pm[s[last]]) {
                    windowCount--;
                }            
            }

            if (windowCount == p.size())
            {
                ans.push_back(i - p.size() + 1);
            }
        }

        return ans;
    }
};

void print(vector<int> &vs)
{
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << " ";
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> ans = s.findAnagrams("cbaebabacd", "abc");
    print(ans);
    ans = s.findAnagrams("abab", "ab");
    print(ans);
}