/*
On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

 

Example 1:


Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Example 2:


Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Example 3:


Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
 

Constraints:

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int board2int(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        int v = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v = v * 10 + board[i][j];
            }
        }
        return v;
    }
    
    vector<vector<int>> int2board(int v) {
        vector<vector<int>> board = vector<vector<int>>(2, vector<int>(3, 0));
        for (int i = 1; i >= 0; i--)
        {
            for (int j = 2; j >= 0; j--)
            {
                board[i][j] = v % 10;
                v = v / 10;
            }
        }
        return board;
    }

    void swap(vector<vector<int>>& board, int x, int y, int nx, int ny) {
        int t = board[x][y];
        board[x][y] = board[nx][ny];
        board[nx][ny] = t;
    }

    vector<int> moveset(int b)
    {
        vector<vector<int>> board = int2board(b);
        vector<int> ms;
        int x = 0;
        int y = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < 0 || ny < 0 || nx == 2 || ny == 3) {
                continue;
            }

            swap(board, x, y, nx, ny);
            ms.push_back(board2int(board));
            swap(board, x, y, nx, ny);
        }
        
        return ms;
    }

    int expected = 123450;

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        int ans = 0;
        unordered_set<int> s;
        queue<int> q;
        q.push(board2int(board));
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                int b = q.front();
                if (b == expected)
                {
                    return ans;
                }
                s.insert(b);
                q.pop();
                vector<int> ms = moveset(b);
                for (int i = 0; i < ms.size(); i++)
                {
                    if (!s.count(ms[i]))
                    {
                        q.push(ms[i]);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> board = {{1,2,3}, {4,0,5}};
    cout << s.slidingPuzzle(board) << endl;
}