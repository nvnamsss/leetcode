/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = vector<vector<int>>{
        {1,0},{0,1},{-1,0},{0,-1}
    };
    void recursive(vector<vector<char>>& board, vector<vector<bool>>& visited, int m, int n, int x, int y) {
        if (visited[x][y]) {
            return;
        }
        visited[x][y] = true;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < 0 || ny < 0 || nx == m || ny == n || visited[nx][ny] || board[nx][ny] == 'X') {
                continue;
            }
            
            recursive(board, visited, m, n, nx, ny);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O') {
                recursive(board, visited, m, n, i, 0);
            } 
            if (board[i][n - 1] == 'O') {
                recursive(board, visited, m, n, i, n - 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O') {
                recursive(board, visited, m, n, 0, i);
            }
            if (board[m-1][i] == 'O') {
                recursive(board, visited, m, n, m - 1, i);
            }
        }
                
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = vector<vector<char>> {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}};
        
    s.solve(board);

}