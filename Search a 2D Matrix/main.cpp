#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        for (int i = 0; i < m; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                r = i;
                break;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (target == matrix[r][i]) return true;
        }
        
        return false;
    }
};