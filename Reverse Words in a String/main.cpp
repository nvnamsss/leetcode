/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void reverse(string &s, int from, int to)
    {
        cout << from << " -> " << to << endl;

        while (from < to)
        {
            char t = s[from];
            s[from] = s[to];
            s[to] = t;
            from++;
            to--;
        }
    }

public:
    string reverseWords(string s)
    {
        int from = 0;
        int trim = 0;
        while (s[trim] == ' ') {
            trim++;
        }   
        s.erase(0, trim);

        reverse(s, 0, s.size() - 1);

        trim = 0;
        while (s[trim] == ' ') {
            trim++;
        }   
        s.erase(0, trim);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (i && s[i - 1] == ' ')
                {
                    s.erase(i, 1);
                    i--;
                }
                else
                {
                    reverse(s, from, i - 1);
                }
                from = i + 1;
            }
        }
        reverse(s, from, s.size() - 1);
        return s;
    }
};

int main()
{
    Solution s;
    string rs = s.reverseWords("the sky is blue");
    cout << rs << endl;

    rs = s.reverseWords("meo");
    cout << rs << endl;

    rs = s.reverseWords("a good   example");
    cout << rs << endl;

    rs = s.reverseWords("  hello world  ");
    cout << rs << endl;
}