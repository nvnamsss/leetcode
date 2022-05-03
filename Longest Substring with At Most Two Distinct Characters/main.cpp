/*
Given a string s, return the length of the longest substring that contains at most two distinct characters.

 

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
 

Constraints:

1 <= s.length <= 105
s consists of English letters.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        char last = '0';
        int lastPos = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) == m.end()) {
                m.insert({s[i], i});
            }

            if (s[i] != last) {
                m[s[i]] = i;
            }

            last = s[i];
            if (m.size() > 2) {
                int posMin = s.size();
                char removed;
                for (auto &&e : m)
                {
                    if (posMin > e.second) {
                        posMin = e.second;
                        removed = e.first;
                    }
                }

                m.erase(removed);
                lastPos = s.size();
                for (auto &&e : m)
                {
                    lastPos = min(lastPos, e.second);
                }
            }

            ans = max(ans, i - lastPos + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstringTwoDistinct("eceba") << endl;
    cout << s.lengthOfLongestSubstringTwoDistinct("abaccc") << endl;
    cout << s.lengthOfLongestSubstringTwoDistinct("aaaaaa") << endl;
    cout << s.lengthOfLongestSubstringTwoDistinct("aabaaa") << endl;
    cout << s.lengthOfLongestSubstringTwoDistinct("aabcaa") << endl;
    cout << s.lengthOfLongestSubstringTwoDistinct("ccaabbb") << endl;
    cout << s.lengthOfLongestSubstringTwoDistinct("a") << endl;
}