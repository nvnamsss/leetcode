/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m;
    int n;
    vector<vector<int>> directions = vector<vector<int>>{
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    bool recursive(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int r, int c, int index) {
        if (index == word.size()) return true;
        visited[r][c] = true;
        for (int i = 0; i < directions.size(); i++)
        {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]){
                continue;
            }

            if (board[nr][nc] == word[index]) {
                if (recursive(board, visited, word, nr, nc, index + 1)) {
                    return true;
                }
            }
        }
        visited[r][c] = false;  

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited =vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0]) {
                    if (recursive(board, visited, word, i, j, 1)) {
                        return true;
                    }
                }
            }
            
        }

        return false;        
    }
};