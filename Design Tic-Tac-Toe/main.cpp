/*
Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that the player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move.
 

Example 1:

Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]

Explanation
TicTacToe ticTacToe = new TicTacToe(3);
Assume that player 1 is "X" and player 2 is "O" in the board.
ticTacToe.move(0, 0, 1); // return 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

ticTacToe.move(0, 2, 2); // return 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

ticTacToe.move(2, 2, 1); // return 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

ticTacToe.move(1, 1, 2); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

ticTacToe.move(2, 0, 1); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

ticTacToe.move(1, 0, 2); // return 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
 

Constraints:

2 <= n <= 100
player is 1 or 2.
0 <= row, col < n
(row, col) are unique for each different call to move.
At most n2 calls will be made to move.
 

Follow-up: Could you do better than O(n2) per move() operation?
*/

#include <bits/stdc++.h>
using namespace std;

class TicTacToe {
    vector<vector<int>> rows;
    vector<vector<int>> columns;
    int diagonal;
    int anti_diagonal;
    int player_diagonal;
    int player_anti_diagonal;
    int n;
public:
    TicTacToe(int n) {
        rows = vector<vector<int>>(n, {-1, n});
        columns = vector<vector<int>>(n, {-1, n});
        diagonal = n;
        anti_diagonal = n;

        player_diagonal = -1;
        player_anti_diagonal = -1;
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        // diagonal
        if (row == col) {
            if (player_diagonal == -1 || player_diagonal == player) {
                diagonal--;
                if (diagonal == 0) {
                    return player;
                }
            }
            player_diagonal = player;
        }

        // anti diagonal
        if (row + col == n - 1) {
            if (player_anti_diagonal == -1 || player_anti_diagonal == player) {
                anti_diagonal--;
                if (anti_diagonal == 0) {
                    return player;
                }
            }
            player_anti_diagonal = player;
        }

        
        if (rows[row][0] == -1 || rows[row][0] == player) {
            rows[row][1]--;
            if (rows[row][1] == 0) {
                return player;
            }
            rows[row][0] = player;
        }

        if (columns[col][0] == -1 || columns[col][0] == player) {
            columns[col][1]--;
            if (columns[col][1] == 0) {
                return player;
            }
            columns[col][0] = player;
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */