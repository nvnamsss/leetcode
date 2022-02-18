#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n - 1;
        while (r >= 0 && r < m && c >= 0 && c < n) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                r++;
            } else {
                c--;
            }
        }
       
        return false;                
    }
};