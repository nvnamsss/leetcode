/*
Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: s = "12345"
Output: ["12345"]
Example 4:

Input: s = "0"
Output: ["0"]
 

Constraints:

s will be a string with length between 1 and 12.
s will consist only of letters or digits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void recursive(vector<string>& result, string s, int k) {
        if (k == s.size()) {
            result.push_back(s);
            return;
        }

        if (s[k] >= 'A' && s[k] <= 'Z') {
            recursive(result, s, k + 1);
            s[k] = s[k] - 'A' + 'a';
            recursive(result, s, k + 1);        
            s[k] = s[k] + 'A' - 'a';
        } else if (s[k] >= 'a' && s[k] <= 'z') {
            recursive(result, s, k + 1);
            s[k] = s[k] - 'a' + 'A';
            recursive(result, s, k + 1);        
            s[k] = s[k] + 'a' - 'A';
        } else {
            recursive(result, s, k + 1);
        }

    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        recursive(result, s, 0);
        return result;
    }
};