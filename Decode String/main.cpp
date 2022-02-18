/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getDigit(char c)
    {
        if (c < '0' || c > '9')
            return -1;
        return c - '0';
    }

public:
    string decodeString(string s)
    {
        string ans = "";
        int times = s[0];
        int i = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int t = getDigit(s[i]);
            if (t == -1)
            {
                ans = ans + s[i];
            }
            else
            {
                while (getDigit(s[i + 1]) != -1)
                {
                    t = t * 10 + getDigit(s[i + 1]);
                    i++;
                }

                string sub = "";
                int open = 1;
                i = i + 2;
                while (true)
                {
                    if (s[i] == '[')
                    {
                        open++;
                    }
                    else if (s[i] == ']')
                    {
                        open--;
                    }
                    if (open > 0)
                    {
                        sub += s[i];
                    }
                    else
                    {
                        break;
                    }
                    i++;
                }

                string subans = decodeString(sub);
                for (int j = 0; j < t; j++)
                {
                    ans += subans;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("3[a]2[bc]") << endl;
}