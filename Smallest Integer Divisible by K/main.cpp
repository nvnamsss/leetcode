#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        int remainder = 0;
        for (int i = 1; i <= k; i++)
        {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0)
            {
                return i;
            }
        }

        return -1;
    }
};