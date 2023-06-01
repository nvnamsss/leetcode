/*
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.



Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation:
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation:
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation:
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".


Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Parentheses
    {
        vector<Parentheses*> child;
        
        Parentheses() {
            child = vector<Parentheses*>();
        }

        string tostring()
        {
            string ans = "(";
            for (int i = 0; i < child.size(); i++)
            {
                ans += child[i]->tostring();
            }
            ans += ")";
            return ans;
        }

        string getans()
        {
            string ans = "";
            for (int i = 0; i < child.size(); i++)
            {
                ans += child[i]->tostring();
            }
            return ans;
        }
    };

public:
    string removeOuterParentheses(string s)
    {
        Parentheses *p = new Parentheses();
        string ans;
        stack<Parentheses *> parents;
        parents.push(p);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                Parentheses *n = new Parentheses();
                Parentheses *t = parents.top();
                t->child.push_back(n);
                parents.push(n);
            } else {
                parents.pop();
            }
        }

        for (int i = 0; i < p->child.size(); i++)
        {
            ans += p->child[i]->getans();
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.removeOuterParentheses("(()())(())") << endl;
    cout << s.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << s.removeOuterParentheses("()()") << endl;

}