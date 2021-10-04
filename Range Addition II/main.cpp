#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int x = m;
        int y = n;
        for (int i = 0; i < ops.size(); i++)
        {
            // need to find the intersection of  x y and ops[i][0] ops[i][1]
            x = min(x, ops[i][0]);
            y = min(y, ops[i][1]);
        }

        return x * y;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ops = vector<vector<int>>{
        {2, 2},
        {3, 3}};
    int rs = s.maxCount(3, 3, ops);
    cout << "result: " << rs << endl;

    ops = vector<vector<int>>{
        {2,2},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3}
    };
    rs = s.maxCount(3, 3, ops);
    cout << "result: " << rs << endl;
    
    ops = vector<vector<int>>{};
    rs = s.maxCount(3, 3, ops);
    cout << "result: " << rs << endl;
}