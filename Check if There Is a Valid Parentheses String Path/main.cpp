/*
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.



Example 1:


Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.
Example 2:


Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is either '(' or ')'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct oc
    {
        vector<vector<int>> os;
    };
    vector<vector<int>> directions = {
        {1, 0}, {0, 1}};

    int m;
    int n;
    int count = 0;
    bool dfs(vector<vector<char>> &grid, vector<vector<vector<int>>> &dp, int x, int y)
    {

        return false;
    }

    bool recursive(vector<vector<char>> &grid, int open, int close, int x, int y)
    {
        // if (open < close || open - close > m - x + n - y) {
        //     return false;
        // }
        if (x == m - 1 && y == n - 1)
        {
            cout << count << endl;
            count++;
            return open == close;
        }

        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx == m || ny == n)
            {
                continue;
            }

            if (grid[nx][ny] == ')' && open <= close)
            {
                continue;
            }

            if (grid[nx][ny] == '(')
            {
                if (recursive(grid, open + 1, close, nx, ny))
                {
                    return true;
                }
            }
            else
            {
                if (recursive(grid, open, close + 1, nx, ny))
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool dpapproach(vector<vector<char>> &grid)
    {
        if (grid[0][0] == ')')
        {
            return false;
        }
        m = grid.size();
        n = grid[0].size();
        vector<vector<unordered_set<int>>> dp = vector<vector<unordered_set<int>>>(m, vector<unordered_set<int>>(n));
        dp[0][0].insert(1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < directions.size(); k++)
                {
                    int x = i - directions[k][0];
                    int y = j - directions[k][1];

                    if (x >= 0 && y >= 0)
                    {
                        int incr = grid[i][j] == '(' ? 1 : -1;
                        unordered_set<int> s = dp[x][y];
                        for (auto &&it : s)
                        {
                            if (dp[i][j].find(it + incr) == dp[i][j].end())
                            {
                                dp[i][j].insert(it + incr);
                            }
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1].find(0) != dp[m - 1][n - 1].end();
    }

public:
    bool hasValidPath(vector<vector<char>> &grid)
    {
        return dpapproach(grid);
        m = grid.size();
        n = grid[0].size();
        count = 0;

        if (grid[0][0] == ')')
        {
            return false;
        }

        return recursive(grid, 1, 0, 0, 0);
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {{'(', '(', '('}, {')', '(', ')'}, {'(', '(', ')'}, {'(', '(', ')'}};
    cout << s.hasValidPath(grid) << endl;
    grid = {{'(', ')', ')', '(', '(', '(', '(', ')', ')', '(', ')', '(', ')', '(', '(', '(', '(', ')', '(', ')', '('}, {'(', '(', ')', ')', '(', ')', ')', ')', '(', ')', '(', ')', '(', '(', ')', '(', '(', '(', '(', '(', ')'}, {')', ')', '(', ')', ')', '(', '(', ')', '(', '(', ')', '(', ')', ')', '(', ')', ')', '(', '(', ')', ')'}, {'(', '(', ')', '(', ')', '(', ')', ')', ')', '(', ')', '(', '(', ')', '(', ')', ')', '(', ')', ')', ')'}, {'(', '(', '(', ')', '(', '(', ')', '(', ')', ')', '(', ')', ')', ')', ')', ')', ')', '(', ')', '(', '('}, {')', ')', '(', '(', ')', ')', ')', ')', ')', '(', ')', ')', ')', '(', '(', ')', '(', '(', '(', '(', ')'}, {')', ')', ')', ')', '(', ')', '(', ')', '(', '(', ')', '(', '(', ')', '(', '(', ')', ')', '(', ')', '('}, {'(', ')', '(', '(', '(', ')', ')', ')', ')', '(', '(', ')', '(', '(', ')', ')', '(', ')', ')', ')', '('}, {'(', ')', '(', ')', '(', '(', '(', '(', ')', '(', '(', '(', '(', '(', '(', ')', '(', ')', '(', ')', ')'}, {'(', ')', '(', '(', '(', ')', '(', ')', ')', ')', ')', '(', '(', '(', '(', ')', ')', '(', '(', '(', ')'}, {'(', '(', ')', '(', ')', ')', '(', ')', '(', ')', ')', ')', ')', ')', '(', ')', '(', ')', ')', ')', '('}, {')', '(', '(', '(', ')', '(', ')', ')', '(', ')', '(', ')', '(', '(', ')', '(', '(', ')', '(', '(', ')'}, {'(', ')', '(', ')', ')', '(', '(', ')', '(', ')', '(', ')', ')', ')', '(', '(', '(', '(', ')', '(', ')'}, {'(', '(', ')', '(', ')', ')', '(', '(', '(', ')', '(', ')', '(', '(', ')', ')', '(', '(', '(', ')', ')'}, {'(', '(', '(', '(', ')', ')', '(', ')', '(', '(', '(', ')', ')', '(', ')', '(', ')', ')', ')', ')', '('}, {'(', '(', '(', ')', ')', ')', '(', ')', ')', '(', ')', ')', '(', '(', ')', '(', ')', '(', '(', '(', ')'}, {')', ')', ')', ')', ')', ')', '(', ')', ')', ')', '(', '(', ')', '(', ')', '(', '(', '(', '(', ')', ')'}};
    cout << s.hasValidPath(grid) << endl;
}