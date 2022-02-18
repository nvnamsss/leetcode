/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int search(vector<int>& v, int target) {
        int l = 0;
        int r = v.size() - 1;
        if (r < 0 || target > v[r]) {
            return -1;
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (v[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        if (v[l] > target) return v[l];
        if (l + 1 == v.size()) return -1;
        return v[l + 1];
    }

public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < t.size(); i++)
        {
            m[t[i]].push_back(i);
        }
        
        int pos = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int next = search(m[s[i]], pos);
            if (next == -1) {
                return false;
            }
            pos = next;
        }

        return true;        
    }
};

int main() {
    Solution s;
    bool rs= s.isSubsequence("abc", "ahbgdc");
    cout << rs << endl;

    rs = s.isSubsequence("axc", "ahbgdc");
    cout << rs << endl;

    rs = s.isSubsequence("abc", "ahcgdb");
    cout << rs << endl;

    rs = s.isSubsequence("aaaaaa", "bbaaaa");
    cout << rs << endl;

    rs = s.isSubsequence("rjufvjafbxnbgriwgokdgqdqewn", "mjmqqjrmzkvhxlyruonekhhofpzzslupzojfuoztvzmmqvmlhgqxehojfowtrinbatjujaxekbcydldglkbxsqbbnrkhfdnpfbuaktupfftiljwpgglkjqunvithzlzpgikixqeuimmtbiskemplcvljqgvlzvnqxgedxqnznddkiujwhdefziydtquoudzxstpjjitmiimbjfgfjikkjycwgnpdxpeppsturjwkgnifinccvqzwlbmgpdaodzptyrjjkbqmgdrftfbwgimsmjpknuqtijrsnwvtytqqvookinzmkkkrkgwafohflvuedssukjgipgmypakhlckvizmqvycvbxhlljzejcaijqnfgobuhuiahtmxfzoplmmjfxtggwwxliplntkfuxjcnzcqsaagahbbneugiocexcfpszzomumfqpaiydssmihdoewahoswhlnpctjmkyufsvjlrflfiktndubnymenlmpyrhjxfdcq");
    cout << rs << endl;

    rs = s.isSubsequence("leetcode", "ylyeyeytycyoydye");
    cout << rs << endl;
}