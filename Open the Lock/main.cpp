#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 10000;

public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> mdead;
        for (int i = 0; i < deadends.size(); i++)
        {
            mdead.insert(deadends[i]);
        }

        int ans = 0;
        queue<string> q;
        q.push("0000");

        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                string v = q.front();
                q.pop();
                if (mdead.count(v))
                {
                    continue;
                }
                mdead.insert(v);
                if (v == target)
                {
                    return ans;
                }

                for (int j = 0; j < 4; j++)
                {
                    int c = v[j] - '0';
                    int up = (c + 1) % 10;
                    int down = (c + 9) % 10;
    
                    string s = v;
                    s[j] = up + '0';
                    q.push(s);
                    s[j] = down + '0';
                    q.push(s);
                }
            }
            ans++;
        }

        return -1;
    }
};