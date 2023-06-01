#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> moves = {
        {1, 2}, {-1, 2}, {1, -2}, {-1, -2},
        {2, 1}, {-2, 1}, {2, -1}, {-2, -1}
    };
    double recursive(vector<vector<vector<double>>>& dp, int n, int k, int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= n) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }

        if (dp[r][c][k] != -1) {
            return dp[r][c][k];
        }
        double valid = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            int nr = r + moves[i][0];
            int nc = c + moves[i][1];

            valid += recursive(dp, n, k - 1, nr, nc);
        }
        dp[r][c][k] = valid;
        return valid;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        double m = recursive(dp, n, k, row, column);
        return (double)m / pow(8, k);
    }
};

int main() {
    Solution s;
    cout << s.knightProbability(8, 30, 6, 4) << endl;
    cout << s.knightProbability(3, 2, 0, 0) << endl;
}