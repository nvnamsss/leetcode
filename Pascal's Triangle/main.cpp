#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rs;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> v = vector<int>(i + 1, 0);
            v[0] = 1;
            v[i] = 1;
            for (int j = 1; j < i; j++)
            {
                int upperLeft = rs[i][j-1];
                int upperRight = rs[i][j];
                v[j] = upperLeft + upperRight;
            }
            rs.push_back(v);
        }
        
        return rs;
    }
};