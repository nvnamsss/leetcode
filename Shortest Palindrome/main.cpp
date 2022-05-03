/*
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        // ABXCABCABX
        string rev(s);
        reverse(rev.begin(), rev.end());
        string ns = s + "#" + rev;
        vector<int> lps = vector<int>(ns.size(), 0);
        for (int i = 1; i < ns.size(); i++)
        {
            int t = lps[i - 1];
            while (t > 0 && ns[i] != ns[t]) {
                t = lps[t - 1];
            }

            if (ns[i] == ns[t]) {
                t++;
            }
            lps[i] = t;
        }
        return rev.substr(0, s.size() - lps[ns.size() - 1]) + s;
    }
};

int main() {
    Solution s;
    cout << s.shortestPalindrome("aacecaaa") << endl;
    cout << s.shortestPalindrome("acbd") << endl;
}