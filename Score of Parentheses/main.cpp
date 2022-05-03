/*
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
 

Constraints:

2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int index = 0;
    int recursive(string s) {
        int ans = 0;
        
        while (s[index + 1] != ')') {
            index++;
            ans += recursive(s);
        }
        index++;
        return ans == 0 ? 1 : ans * 2;
    }
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        index = 0;
        while (index < s.size()) {
            ans += recursive(s);
            index++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.scoreOfParentheses("(())") << endl;
    cout << s.scoreOfParentheses("(()(())())") << endl;
    cout << s.scoreOfParentheses("(())(())") << endl;
}