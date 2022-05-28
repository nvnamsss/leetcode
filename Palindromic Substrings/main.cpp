/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int countPalindrome(string s, int lower, int upper)
    {
        int count = 1;
        int l = lower - 1;
        int r = upper + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
            count++;
        }
        return count;
    }

public:
    int countSubstrings(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans += countPalindrome(s, i, i);
            if (i+1 < s.size() && s[i] == s[i+1]) {
                 ans += countPalindrome(s, i, i + 1);
            } 
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countSubstrings("abc") << endl;
    cout << s.countSubstrings("aaa") << endl;
}