/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findPeak(vector<int>& row) {
        int l = 0;
        int r = row.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (get(row,m) < get(row, m + 1)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }

    int get(vector<int>& row, int i) {
        if (i < 0 || i == row.size()) {
            return -1;
        }
        return row[i];
    }

    int get(vector<vector<int>>& mat, int x, int y) {
        int m = mat.size();
        int n = mat[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n) {
            return - 1;
        }
        return mat[x][y];
    }
    vector<int> binarySearch(vector<vector<int>>& mat, int upper, int lower) {
        if (upper > lower) {
            return {-1, -1};
        }

        int n = mat.size();
        int central = (lower + upper) / 2;
        int upperSide = central - 1;
        int lowerSide = central + 1;

        int peak = findPeak(mat[central]);
        int cValue = get(mat, central, peak);
        int uValue = get(mat, upperSide, peak);
        int lValue = get(mat, lowerSide, peak);
        if (cValue > uValue && cValue > lValue) {
            return {central, peak};
        }

        vector<int> u = binarySearch(mat, upper, central - 1);
        if (u[0] != -1) {
            return u;
        }

        return binarySearch(mat, central + 1, lower);
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        return binarySearch(mat, 0, mat.size());
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1,4},{3,2}};
    vector<int> ans = s.findPeakGrid(mat);
    cout << ans[0] << "," << ans[1] << endl;

    mat = {{10,20,15},{21,30,14},{7,16,32}};
    ans = s.findPeakGrid(mat);
    cout << ans[0] << "," << ans[1] << endl;

    mat = {{10,20,15}};
    ans = s.findPeakGrid(mat);
    cout << ans[0] << "," << ans[1] << endl;

    mat ={{25,37,23,37,19},{45,19,2,43,26},{18,1,37,44,50}};
    ans = s.findPeakGrid(mat);
    cout << ans[0] << "," << ans[1] << endl;

    mat = {{10,50,40,30,20},{1,500,2,3,4}};
    ans = s.findPeakGrid(mat);
    cout << ans[0] << "," << ans[1] << endl;
}