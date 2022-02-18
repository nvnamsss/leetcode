/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
    void reverse(string& s, int from, int to) {
        while (from < to) {
            char t = s[from];
            s[from] = s[to];
            s[to] = t;
            from++;
            to--;
        }
    }
public:
    string reverseWords(string s) {
        int from = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ') {
                reverse(s, from, i - 1);
                from = i + 1;
            } else if (i == s.size() - 1) {
                reverse(s, from, i);              
            }
        }
        return s;
    }
};