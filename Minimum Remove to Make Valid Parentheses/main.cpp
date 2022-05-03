/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 

Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        /*
        (()()))
        */
        queue<int> qo;
        queue<int> qc;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                qo.push(i);
            }
            else if (s[i] == ')')
            {
                qc.push(i);
            }
        }

        while (!qo.empty() || !qc.empty())
        {
            if (qo.empty() || (!qc.empty() && qo.front() > qc.front()))
            {
                s[qc.front()] = '1';
                qc.pop();
            }
            else if (qc.empty())
            {
                // s = s.erase(qo.front(), 1);
                s[qo.front()] = '1';
                qo.pop();
            }
            else
            {
                qo.pop();
                qc.pop();
            }
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '1')
            {
                ans += s[i];
            }
        }

        return ans;
    }

    string minRemoveToMakeValid2(string s)
    {
        /*
        (()()))
        */

        int balance = 0;
        int open = 0;
        string pre_ans = "";
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                open++;
                balance++;
            }
            else if (s[i] == ')')
            {
                if (balance == 0) continue;
                balance--;
            }

            pre_ans += s[i];
        }

        int open = open - balance;
        for (int i = 0; i < pre_ans.size(); i++)
        {
            if (pre_ans[i] == '(') {
                open--;
                if (open < 0) continue;
            }

            ans += pre_ans[i];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    string rs = s.minRemoveToMakeValid("lee(t(c)o)de)");
    cout << rs << endl;
    rs = s.minRemoveToMakeValid("(a(b(c)d)");
    cout << rs << endl;
    rs = s.minRemoveToMakeValid(")))(((");
    cout << rs << endl;
};