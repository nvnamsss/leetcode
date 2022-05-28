/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.



Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int iterative(string s)
    {
        int close = 0;
        vector<int> streaks = vector<int>(s.size());
        vector<int> previous = vector<int>(s.size(), -1);
        stack<int> open;
        int lastClose = -1;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                previous[i] = lastClose;
                lastClose = i;
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                open.push(i);
            }
            else
            {
                if (open.empty())
                {
                    continue;
                }
                open.pop();
                if (previous[i] == -1)
                {
                    streaks[i] = 1;
                    ans = max(ans, 1);
                    continue;
                }
                streaks[i] = streaks[previous[i]] + 1;
                ans = max(ans, streaks[i]);
            }
        }
        return ans * 2;
    }

    int stackApproach(string s) {
        stack<int> st;
        int streak = 0;
        int ans = 0;
        st.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') {
                st.push(i);
            } else {
                int last = st.top();
                if (last == -1) {
                    streak = 0;
                    continue;
                }
                st.pop();
                if (st.top() != -1) {
                    ans = max(ans, i - last + 1);
                } else {
                    ans = max(ans , streak + i - last + 1);
                    streak += i - last + 1;
                }
                // streak += 2;
            }
        }
        return ans;
    }

    int dp(string s)
    {
        int ans = 0;
        vector<int> dp = vector<int>(s.size());
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ')' && s[i - 1] == '(')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }

            if (s[i] == ')' && s[i - 1] == ')')
            {
                if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }

public:
    int longestValidParentheses(string s)
    {
        return stackApproach(s);
    }
};

int main()
{
    Solution s;
    cout << s.longestValidParentheses(")()())") << endl;
    cout << s.longestValidParentheses("(()") << endl;
    cout << s.longestValidParentheses(")()())()()(") << endl;
    cout << s.longestValidParentheses(")()()()())))") << endl;
    cout << s.longestValidParentheses("))))((((") << endl;
    cout << s.longestValidParentheses("()()") << endl;
    cout << s.longestValidParentheses("()(()") << endl;
    cout << s.longestValidParentheses("()())))") << endl;
    cout << s.longestValidParentheses("()()(((()))))))") << endl;
    cout << s.longestValidParentheses("()()))))))))))((((((((((((((()()()()((()()))))()()()()())))))))))))())()()()()())))))))))))))))((") << endl;
}