/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getDigit(char c)
    {
        return c - '0';
    }

    char getChar(int digit)
    {
        return digit + '0';
    }

public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        string rs = string(num1.size() + num2.size() - 1, '0');
        int r = 0;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int p = i;
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int writeTo = p + j;
                int v1 = getDigit(num1[i]);
                int v2 = getDigit(num2[j]);
                int v = getDigit(rs[writeTo]) + v1 * v2 + r;
                rs[writeTo] = getChar(v % 10);
                r = v / 10;
            }
            if (r && i) {
                rs[i - 1] = getChar(getDigit(rs[i - 1]) + r);
                r = 0;
            }
        }
        while (r > 0)
        {
            rs = getChar(r % 10) + rs;
            r = r / 10;
        }

        return rs;
    }
};

int main()
{
    Solution s;
    string rs = s.multiply("123", "456");
    cout << rs << endl;
}