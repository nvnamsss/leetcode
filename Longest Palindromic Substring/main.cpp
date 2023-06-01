#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int expand(string s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }

        return r - l - 1;
    }

public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0)
        {
            return s;
        }
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int l1 = expand(s, i, i);
            int l2 = expand(s, i, i + 1);
            int l = max(l1, l2);
            if (l > end - start)
            {
                end = i + l / 2;
                start = i - (l - 1) / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main()
{
    Solution s;
    string rs = s.longestPalindrome("babad");
    cout << rs << endl;
    rs = s.longestPalindrome("sbbd");
    cout << rs << endl;
    rs = s.longestPalindrome("sbbs");
    cout << rs << endl;
}