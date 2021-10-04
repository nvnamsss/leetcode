using System;
using System.Collections.Generic;

public class Solution
{
    public int CompareVersion(string version1, string version2)
    {
        string[] v1 = version1.Split(".");
        string[] v2 = version2.Split(".");
        int length = Math.Max(v1.Length, v2.Length);

        for (int loop = 0; loop < length; loop++)
        {
            string sr1 = loop < v1.Length ? v1[loop].TrimStart('0') : "0";
            string sr2 = loop < v2.Length ? v2[loop].TrimStart('0') : "0";
            if (sr1 == "") sr1 = "0";
            if (sr2 == "") sr2 = "0";

            int r1 = int.Parse(sr1);
            int r2 = int.Parse(sr2);
            if (r1 > r2) return 1;
            if (r1 < r2) return -1;
        }

        return 0;
    }

    public string Multiply(string num1, string num2)
    {
        string rs = "0";
        for (int i = 0; i < num2.Length; i++)
        {
            string s = multiply(num1, num2[i]);
            for (int j = i + 1; j < num2.Length; j++)
            {
                s = s + "0";
            }
            rs = plus(rs, s);

        }
        rs = rs.TrimStart('0');
        if (rs == string.Empty) rs = "0";
        return rs;
    }

    string multiply(string num1, char c)
    {
        string rs = string.Empty;
        int size = num1.Length;
        int r = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            int t = (num1[i] - '0') * (c - '0') + r;
            char append = (char)(t % 10 + '0');
            r = t / 10;
            rs = append + rs;
        }

        while (r > 0)
        {
            char append = (char)(r % 10 + '0');
            rs = append + rs;
            r = r / 10;
        }
        return rs;
    }

    string plus(string num1, string num2)
    {
        string rs = string.Empty;
        int s1 = num1.Length;
        int s2 = num2.Length;
        int length = Math.Max(s1, s2);
        int r = 0;

        if (s1 < s2)
        {
            for (int i = length - s1; i > 0; i--)
            {
                num1 = '0' + num1;
            }
        }
        else
        {
            for (int i = length - s2; i > 0; i--)
            {
                num2 = '0' + num2;
            }
        }

        for (int i = length - 1; i >= 0; i--)
        {
            int a = num1[i] + num2[i];
            int b = 2 * '0';
            int t = (a - b + r);
            r = t / 10;
            char append = (char)(t % 10 + '0');
            rs = append + rs;
        }

        if (r > 0)
        {
            char append = (char)(r % 10 + '0');
            rs = append + rs;
        }  

        return rs;
    }
}