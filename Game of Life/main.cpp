#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {
        {1,0},{-1,0},{0,1},{0,-1},
        {1,1},{-1,1},{1,-1},{-1,-1},
    };
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int live = 0;
                int dead = 0;
                for (int k = 0; k < directions.size(); k++)
                {
                    int x = i + directions[k][0];
                    int y = j + directions[k][1];
                    if (x < 0 || y < 0 || x == m || y == n) continue;
                    
                    if (board[x][y] == 1 || board[x][y] == -1) {
                        live++;
                    }

                    if (board[x][y] == 0 || board[x][y] == -2) {
                        dead++;
                    }
                }

                if (board[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        board[i][j] = -1;
                    }
                }

                if (board[i][j] == 0 && live == 3) {
                    // resurrect
                    board[i][j] = -2;
                }

            }
                        
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == -1) board[i][j] = 0;
                if (board[i][j] == -2) board[i][j] = 1;
            }
        }
              
    }
};