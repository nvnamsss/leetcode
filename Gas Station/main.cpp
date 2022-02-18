#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int ans = 0;
        int total = 0;
        int current = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int dif = gas[i] - cost[i];
            total += dif;
            current += dif;
            if (current < 0)
            {
                current = 0;
                ans = i + 1;
            }
        }

        if (total < 0)
            return -1;
        return ans;
    }
};