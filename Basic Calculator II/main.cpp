/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> values;
        stack<char> operators;
        unordered_map<char, int> set = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        int ans = 0;
        int last = 0;
        int current = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;

            if (set.count(s[i]))
            {
                if (sign == '+' || sign == '-')
                {
                    ans += last;
                    last = sign == '+' ? current : -current;
                }
                else if (sign == '*')
                {
                    last = last * current;
                }
                else
                {
                    last = last / current;
                }
                sign = s[i];
                operators.push(s[i]);
                current = 0;
            }
            else
            {
                current = current * 10 + (s[i] - '0');
            }
        }

        if (sign == '+') {
            last = last + current;
        }
        else if (sign == '-') {
            last = last - current;
        }
        else if (sign == '*')
        {
            last = last * current;
        }
        else
        {
            last = last / current;
        }

        ans += last;
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.calculate("3+2*2") << endl;
    cout << s.calculate("  3/2  ") << endl;
    cout << s.calculate("  3 + 5/2 ") << endl;
    cout << s.calculate("2147483647") << endl;
    cout << s.calculate("1+1-1") << endl;
    cout << s.calculate("14*3/2") << endl;
}