#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rs = vector<vector<int>>(n, vector<int>(n, 0));
        vector<pair<int, int>> directions = vector<pair<int, int>>{
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}};
        int m = n * n;
        int d = 0;
        int x = 0;
        int y = 0;

        for (int i = 1; i <= m; i++)
        {
            rs[x][y] = i;
            int xn = x + directions[d].first;
            int yn = y + directions[d].second;
            if (xn < 0 || xn >= n || yn < 0 || yn >= n || rs[xn][yn] != 0)
            {
                d = (d + 1) % 4;
            }

            x = x + directions[d].first;
            y = y + directions[d].second;
        }

        return rs;
    }
};