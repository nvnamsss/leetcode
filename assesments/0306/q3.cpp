/*
On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.



We may make the following moves:

'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

 

Example 1:

Input: target = "leet"
Output: "DDR!UURRR!!DDD!"
Example 2:

Input: target = "code"
Output: "RR!DDRR!UUL!R!"
 

Constraints:

1 <= target.length <= 100
target consists only of English lowercase letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> pos = {
        {0, 0},
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {1, 0},
        {1, 1},
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 0},
        {2, 1},
        {2, 2},
        {2, 3},
        {2, 4},
        {3, 0},
        {3, 1},
        {3, 2},
        {3, 3},
        {3, 4},
        {4, 0},
        {4, 1},
        {4, 2},
        {4, 3},
        {4, 4},
        {5, 0},
    };

    string pressVerticalFirst(char v, char h, int vtimes, int htimes)
    {
        string cmd = "";

        for (int i = 0; i < vtimes; i++)
        {
            cmd += v;
        }

        for (int i = 0; i < htimes; i++)
        {
            cmd += h;
        }

        cmd += '!';
        return cmd;
    }

    string pressHorizontalFirst(char v, char h, int vtimes, int htimes)
    {
        string cmd = "";
        for (int i = 0; i < htimes; i++)
        {
            cmd += h;
        }
        for (int i = 0; i < vtimes; i++)
        {
            cmd += v;
        }

        cmd += '!';
        return cmd;
    }

    string press(char from, char to)
    {
        vector<int> locF = pos[from - 'a'];
        vector<int> locT = pos[to - 'a'];
        char vertical = locF[0] > locT[0] ? 'U' : 'D';
        char horizontal = locF[1] < locT[1] ? 'R' : 'L';
        int vTimes = abs(locF[0] - locT[0]);
        int hTimes = abs(locF[1] - locT[1]);

        string cmd = "";
        if (locF[0] < locT[0]) {
            cmd = pressHorizontalFirst(vertical, horizontal, vTimes, hTimes);
        } else {
            cmd = pressVerticalFirst(vertical, horizontal, vTimes, hTimes);
        }

        return cmd;
    }

public:
    string alphabetBoardPath(string target)
    {
        string cmd = "";
        char from = 'a';
        for (int i = 0; i < target.size(); i++)
        {
            cmd += press(from, target[i]);
            from = target[i];
        }

        return cmd;
    }
};