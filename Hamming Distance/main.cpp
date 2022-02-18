#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ans = 0;
        int a = max(x, y);
        int b = min(x, y);

        while (a != 0 && b != 0)
        {
            int ra = a & ~(a - 1);
            int rb = b & ~(b - 1);
            if (ra != rb) {
                ans++;
            }
            
            if (ra >= rb)
            {
                b = b & (b - 1);
            }

            if (ra <= rb)
            {
                a = a & (a - 1);
            }
        }

        while (a > 0) {
            a = a & (a - 1);
            ans++;
        }

        while (b > 0) {
            b = b & (b - 1);
            ans++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int rs = s.hammingDistance(1, 4);
    cout << rs << endl;
    rs = s.hammingDistance(3, 1);
    cout << rs << endl;
}