/*
A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.

For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

 

Example 1:

Input: k = 2, n = 5
Output: 25
Explanation:
The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
  base-10    base-2
    1          1
    3          11
    5          101
    7          111
    9          1001
Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
Example 2:

Input: k = 3, n = 7
Output: 499
Explanation:
The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
  base-10    base-3
    1          1
    2          2
    4          11
    8          22
    121        11111
    151        12121
    212        21212
Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
Example 3:

Input: k = 7, n = 17
Output: 20379000
Explanation: The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
 

Constraints:

2 <= k <= 9
1 <= n <= 30
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void mirrorRecursive(vector<string> &rs, int k, int n, int at, int from, string value)
    {
        int nd2 = n / 2;
        if ((n % 2 == 0 && at == nd2) || at > nd2)
        {
            rs.push_back(value);
            return;
        }

        bool middle = at == n - at - 1;
        for (int i = from; i < k; i++)
        {
            if (middle)
            {
                value[at] = getChar(i);
                mirrorRecursive(rs, k, n, at + 1, 0, value);
                value[at] = getChar(from);
            }
            else
            {
                value[at] = getChar(i);
                value[n - at - 1] = getChar(i);
                mirrorRecursive(rs, k, n, at + 1, 0, value);
                value[at] = getChar(from);
                value[n - at - 1] = getChar(from);
            }
        }
    }

    int getDigit(char c)
    {
        return c - '0';
    }

    char getChar(int i)
    {
        return i + '0';
    }

public:
    long long kto10(string value, int k)
    {
        long long ans = 0;
        long long p = 1;
        for (int i = value.size() - 1; i >= 0; i--)
        {
            ans += getDigit(value[i]) * p;
            p *= k;
        }

        return ans;
    }

    vector<string> genMirror(int k, int n)
    {
        vector<string> rs;
        string s = string(n, '0');
        mirrorRecursive(rs, k, n, 0, 1, s);
        return rs;
    }
    bool mirror(long long num)
    {
        //reverse a number, if the reverse of this number is equal to itself
        long long v = num;
        long long reverse = 0;
        long long p = pow(10, floor(log10(num)));
        long long pr = 1;
        while (v)
        {
            reverse += (v / p) * pr;
            v = v % p;
            p = p / 10;
            pr = pr * 10;
        }
        // 1234
        // 4000 + 300 + 20 + 1
        return reverse == num;
    }

    long long kMirror(int k, int n)
    {
        long long ans = 0;
        int digit = 1;

        while (n > 0)
        {
            vector<string> mr = genMirror(k, digit);
            for (int i = 0; i < mr.size() && n > 0; i++)
            {
                long long tenthbase = kto10(mr[i], k);
                if (tenthbase < 0)
                {
                    cout << "himom";
                }
                if (mirror(tenthbase))
                {
                    ans += tenthbase;
                    n--;
                }
            }
            digit++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.mirror(1234) << endl;
    cout << s.mirror(1221) << endl;
    cout << s.mirror(21212) << endl;

    s.genMirror(2, 20);

    cout << s.kto10("11111", 3) << endl;
    cout << s.kto10("12121", 3) << endl;
    cout << s.kto10("21212", 3) << endl;

    cout << s.kMirror(3, 7) << endl;
    cout << s.kMirror(2, 20) << endl;
}