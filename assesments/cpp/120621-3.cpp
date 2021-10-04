/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

/*
Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
Example 4:

Input: columnTitle = "FXSHRXW"
Output: 2147483647
*/

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
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        map<char, int> m;
        for (int loop = 0; loop < s.size(); loop++)
        {
            char c = s[loop];
            if (m.find(c) == m.end())
            {
                m.insert(pair<char, int>(c, 0));
            }

            m[c]++;
        }

        for (int loop = 0; loop < t.size(); loop++)
        {
            char c = t[loop];
            if (m.find(c) == m.end())
                return false;
            m[c]--;
            if (m[c] == 0)
                m.erase(c);
        }

        return true;
    }

    int titleToNumber(string columnTitle)
    {
        int num = 0;
        int n = columnTitle.size() - 1;
        for (int loop = n; loop >= 0; loop--)
        {
            char c = columnTitle[loop];
            int v = c - 'A' + 1;
            num = num + v * pow(26, n - loop);
        }

        return num;
    }
    vector<vector<int>> direction {
        vector<int>{1,0},
        vector<int>{-1,0},
        vector<int>{0,1},
        vector<int>{0,-1},
    };

    string word;
    vector<vector<char>> board;
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        this->word = word;
        this->board = board;
        for (int loop = 0; loop < m; loop++)
        {
            for (int loop2 = 0; loop2 < n; loop2++)
            {
                char bc = board[loop][loop2];
                char sc = word[0];
                if (bc == sc)  {
                    vector<vector<bool>> visited(m);
                    for (int i = 0; i < m; i++)
                    {
                        visited[i] = vector<bool>(n);
                    }
                    if (dfs(visited, loop, loop2, 0)) return true;
                }
            }
        }
        
        return false;
    }

    bool dfs(vector<vector<bool>> visited, int h, int w, int index) {
        if (visited[h][w]) return false;
        visited[h][w] = true;
    }

};