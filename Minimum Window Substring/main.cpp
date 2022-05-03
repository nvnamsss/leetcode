/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> ans = {-1, 0, 0};
        unordered_map<char, int> m;
        for (int i = 0; i < t.size(); i++)
        {
            m[t[i]]++;
        }
        unordered_map<char, int> collection;
        int count = 0;
        int left = 0;
        int right = 0;
        int require = m.size();
        while (right < s.size())
        {
            if (m[s[right]] > 0)
            {
                collection[s[right]]++;
                if (collection[s[right]] == m[s[right]])
                {
                    count++;
                }
            }
            while (left <= right && count == require)
            {
                if (ans[0] == -1 || right - left < ans[0]) {
                    ans[0] = right - left;
                    ans[1] = left;
                    ans[2] = right;
                }

                if (m[s[left]] > 0)
                {
                    collection[s[left]]--;
                    if (collection[s[left]] == m[s[left]] - 1)
                        count--;
                }
                left++;
            }
            right++;
        }

        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.minWindow("ABCA", "A") << endl;
    cout << s.minWindow("A", "AA") << endl;
    cout << s.minWindow("AA", "AA") << endl;


}