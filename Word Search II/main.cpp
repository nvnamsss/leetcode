/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Trie
{
    unordered_map<char, Trie *> tries;

public:
    bool end;
    Trie()
    {
        end = false;
    }

    void add_word(string word)
    {
        Trie *t = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (t->tries.find(word[i]) == t->tries.end())
            {
                Trie *n = new Trie();
                t->tries.insert({word[i], n});
            }
            t = t->tries[word[i]];
        }

        t->end = true;
    }

    Trie *get(char c)
    {
        if (tries.find(c) == tries.end())
            return NULL;
        return tries[c];
    }
};

class Solution
{
    int m;
    int n;
    vector<vector<int>> directions = vector<vector<int>>{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set<string> ans;
    void recursive(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, Trie *t, int r, int c)
    {
        if (t->end)
        {
            if (ans.find(word) == ans.end()) {
                ans.insert(word);
            }
        }

        visited[r][c] = true;
        for (int i = 0; i < directions.size(); i++)
        {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            if (nr < 0 || nr == m || nc < 0 || nc == n || visited[nr][nc])
                continue;
            Trie *next = t->get(board[nr][nc]);
            if (next == NULL)
                continue;

            recursive(board, visited, word + board[nr][nc], next, nr, nc);
        }
        visited[r][c] = false;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size();
        n = board[0].size();
        ans = set<string>{};

        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        Trie *t = new Trie();
        for (int i = 0; i < words.size(); i++)
        {
            t->add_word(words[i]);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Trie *next = t->get(board[i][j]);
                string w = "";

                if (next != NULL)
                {
                    recursive(board, visited, w + board[i][j], next, i, j);
                }
            }
        }

        vector<string> rs;
        for (auto &&i : ans)
        {
            rs.push_back(i);
        }
        
        return rs;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = vector<vector<char>>{
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};
    vector<string> words = vector<string>{"oath", "pea", "eat", "rain"};
    s.findWords(board, words);

    board = vector<vector<char>>{
        {'a', 'b'}
    };
    words =vector<string>{"ab"};
    s.findWords(board, words);

}