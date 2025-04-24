/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        // a a a b b c e d f
        // a b a b c e e d f
        vector<int> freq = vector<int>('z' - 'a' + 1);
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < s.size(); ++i) {
            int p = s[i] - 'a';
            freq[p]++;
        }

        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] > 0) {
                pq.push({freq[i], i + 'a'});
            }
        }

        string ans = "";
        while (!pq.empty()) {
            pair<int, char> current = pq.top();
            pq.pop();
            
            if (ans.size() > 0 && ans[ans.size() - 1] == current.second) {
                if (pq.empty()) {
                    return "";
                }

                pair<int, char> next = pq.top();
                pq.pop();
                ans += next.second;
                next.first--;
                if (next.first > 0) {
                    pq.push(next);
                }
            } else {
                ans += current.second;
                current.first--;
            }

            if (current.first > 0) {
                pq.push(current);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.reorganizeString("aab") << endl;
    cout << s.reorganizeString("aaab") << endl;
    cout << s.reorganizeString("zhmyo") << endl;
}