/*
Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

 

Example 1:

Input: s = "banana"
Output: "ana"
Example 2:

Input: s = "abcd"
Output: ""
 

Constraints:

2 <= s.length <= 3 * 104
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long

class Solution {
public:
    int check(const string &s, int len, ULL power) {
        unordered_set<ULL> seen;
        int n = s.length();

        ULL hash = 0;
        for (int i = 0; i < len; i++)
            hash = hash * 131 + s[i] - 'a';

        seen.insert(hash);

        for (int i = len; i < n; i++) {
            hash = hash - power * (s[i - len] - 'a');
            hash = hash * 131 + s[i] - 'a';
            if (seen.find(hash) != seen.end())
                return i - len + 1;

            seen.insert(hash);
        }

        return -1;
    }

    string longestDupSubstring(string S) {
        int n = S.length();
        int l = 0, r = n - 1;

        vector<ULL> power(n, 1);
        for (int i = 1; i < n; i++){
            power[i] = power[i - 1] * 131;
        }
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(S, mid + 1, power[mid]) == -1)
                r = mid;
            else
                l = mid + 1;
        }

        if (l == 0)
            return "";

        return S.substr(check(S, l, power[l - 1]), l);
    }
};

int main() {
    Solution s;
    string rs = s.longestDupSubstring("banana");
    cout << rs << endl;
    rs = s.longestDupSubstring("abcd");
    cout << rs << endl;

}