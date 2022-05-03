/*
Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

 

Example 1:

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:

Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
Example 3:

Input: s = "LEETCODE"
Output: 92
 

Constraints:

1 <= s.length <= 105
s consists of uppercase English letters only.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int recursive(string s, unordered_map<string, int>& m) {
        if (m.find(s) != m.end()) {
            return m[s];
        }
        int ans = 0;
        vector<bool> existed = vector<bool>(26);
        for (int i = 0; i < s.size(); i++)
        {
            if (!existed[s[i]-'A']) {
                existed[s[i]-'A'] = true;
                ans++;
            }
        }
        
        for (int i = 1; i <= s.size() - 1; i++)
        {
            for (int j = 0; j <= s.size() - i; j++)
            {
                string ss = s.substr(j, i);
                ans += recursive(ss, m);
            }
        }

        m[s] = ans;
        return m[s];
    }
public:
    int uniqueLetterString(string s) {
        unordered_map<string, int> m;
        for (int i = 0; i < 26; i++)
        {
            string ss = "" + (i + 'A');
            m[ss] = 1;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            
        }
        
        return recursive(s, m);
    }
};

int main() {
    Solution s;
    cout << s.uniqueLetterString("ABC") << endl;
    cout << s.uniqueLetterString("LEETCODE") << endl;
}