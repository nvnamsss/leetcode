#include <bits/stdc++.h>
using namespace std;

class Solution2 {
    public:
    int maxPathSum(vector<vector<int>>& board, int p, int q) {
        // start from (0, p) or (rows - 1, q)
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> dp_down(m, vector<int>(n, 0));
        vector<vector<int>> dp_up(m, vector<int>(n, 0));
        dp_down[0][p] = board[0][p];
        dp_up[m - 1][q] = board[m - 1][q];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp_down[i][j] = board[i][j] + max(dp_down[i - 1][j], max(j > 0 ? dp_down[i - 1][j - 1] : 0, j < n - 1 ? dp_down[i - 1][j + 1] : 0));
            }
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp_up[i][j] = board[i][j] + max(dp_up[i + 1][j], max(j > 0 ? dp_up[i + 1][j - 1] : 0, j < n - 1 ? dp_up[i + 1][j + 1] : 0));
            }
        }

        int res = 0;
        for (int j = 0; j < n; j++) {
            res = max(res, dp_down[m - 1][j]);
            res = max(res, dp_up[0][j]);
        }
        return res;
    }
};
// Test helper function for Solution2
bool runTest2(vector<vector<int>> board, int p, int q, int expected) {
    Solution2 sol;
    int result = sol.maxPathSum(board, p, q);
    
    cout << "Board: [" << endl;
    for (const auto& row : board) {
        cout << "  [";
        for (size_t i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    cout << "Start positions: (0, " << p << ") or (" << board.size() - 1 << ", " << q << ")" << endl;
    cout << "Expected: " << expected << ", Got: " << result << endl;
    
    bool passed = result == expected;
    cout << (passed ? "PASSED" : "FAILED") << endl << endl;
    return passed;
}

int main() {
    int passed = 0, total = 0;
    
    // Test case 1: Simple 3x3 board
    // Board:
    // [1, 3, 1]
    // [2, 5, 2]
    // [3, 6, 4]
    // Starting from (0,1) = 3 or (2,1) = 6
    // Best path: (2,1) -> (1,1) -> (0,1) = 6 + 5 + 3 = 14
    passed += runTest2({{1, 3, 1}, {2, 5, 2}, {3, 6, 4}}, 1, 1, 14);
    total++;
    
    // Test case 2: Board with negative numbers
    // Board:
    // [1, -5, 1]
    // [2, -8, 2]
    // [10, -3, 4]
    // Starting from (0,0) = 1 or (2,0) = 10
    // Best path: (2,0) -> (1,1) -> (0,2) = 10 + (-8) + 1 = 3
    passed += runTest2({{1, -5, 1}, {2, -8, 2}, {10, -3, 4}}, 0, 0, 13);
    total++;
    
    // Test case 3: Edge case - 1x1 board
    // Single cell with value 5
    passed += runTest2({{5}}, 0, 0, 5);
    total++;
    
    // Test case 4: Edge case - starting positions at edges
    // Board:
    // [5, 2, 3]
    // [1, 8, 4]
    // [7, 6, 9]
    // Starting from (0,0) = 5 or (2,2) = 9
    // Best path from (0,0): (0,0) -> (1,1) -> (2,2) = 5 + 8 + 9 = 22
    // Best path from (2,2): (2,2) -> (1,1) -> (0,0) = 9 + 8 + 5 = 22
    passed += runTest2({{5, 2, 3}, {1, 8, 4}, {7, 6, 9}}, 0, 2, 22);
    total++;
    
    // Test case 5: Larger board with optimal diagonal path
    // Board:
    // [1, 2, 3, 4]
    // [5, 6, 7, 8]
    // [9, 10, 11, 12]
    // [13, 14, 15, 16]
    // Starting from (0,2) = 3 or (3,1) = 14
    // Best path: (0,2) -> (1,3) -> (2,3) -> (3,3) = 3 + 8 + 12 + 16 = 39
    passed += runTest2({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 2, 1, 39);
    total++;
    
    // Test case 6: Board with same optimal path from both starting positions
    // Board:
    // [3, 5, 2]
    // [4, 8, 3]
    // [1, 6, 2]
    // Starting from (0,1) = 5 or (2,1) = 6
    // Both paths converge to middle column: 5 + 8 + 6 = 19 or 6 + 8 + 5 = 19
    passed += runTest2({{3, 5, 2}, {4, 8, 3}, {1, 6, 2}}, 1, 1, 19);
    total++;
    
    // Test case 7: Board with all zeros except starting positions
    // Board:
    // [0, 10, 0]
    // [0, 0, 0]
    // [0, 15, 0]
    // Starting from (0,1) = 10 or (2,1) = 15
    // Best path: (2,1) = 15
    passed += runTest2({{0, 10, 0}, {0, 0, 0}, {0, 15, 0}}, 1, 1, 25);
    total++;
    
    // Test case 8: Very wide board
    // Tests edge cases where j-1 or j+1 might go out of bounds
    vector<vector<int>> wideBoard(3, vector<int>(10, 1));
    wideBoard[0][0] = 5;  // Special value at (0,0)
    wideBoard[2][9] = 10; // Special value at (2,9)
    // Starting from (0,0) = 5 or (2,9) = 10
    // Best path from (2,9): 10
    passed += runTest2(wideBoard, 0, 9, 12);
    total++;
    
    cout << "Passed " << passed << " out of " << total << " tests." << endl;
    
    return 0;
}