/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.



Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"


Constraints:

1 <= n <= 30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> say(string s)
    {
        vector<vector<int>> ans;
        int i = 0;
        char c = ' ';
        while (i < s.size())
        {
            if (s[i] != c)
            {
                ans.push_back({s[i] - '0', 0});
                c = s[i];
            }
            ans[ans.size() - 1][1]++;
            i++;
        }
        return ans;
    }

    string read(vector<vector<int>> &s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            ans += (s[i][1] + '0');
            ans += (s[i][0] + '0');
        }
        return ans;
    }

public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 1; i < n; i++)
        {
            vector<vector<int>> s = say(ans);
            ans = read(s);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(4) << endl;
}