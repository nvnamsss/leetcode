#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    unordered_map<char, Trie *> tries;
    bool end;
    Trie()
    {
        end = false;
    }

    void parse(string s)
    {
        Trie *t = this;
        for (int i = 0; i < s.size(); i++)
        {
            if (t->tries.find(s[i]) == t->tries.end())
            {
                t->tries.insert({s[i], new Trie()});
            }

            t = t->tries[s[i]];
        }
        t->end = true;
    }
    void remove(char c)
    {
        tries.erase(c);
    }

    bool empty()
    {
        return tries.empty();
    }
};

class Solution
{
    Trie *t;
    int m, n;
    vector<vector<int>> directions{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void recursive(vector<vector<char>> &board, vector<vector<bool>> &visited, unordered_set<string> &ans, Trie *t, string s, int x, int y)
    {
        if (t->end)
        {
            ans.insert(s);
            t->end = false;
        }

        visited[x][y] = true;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < 0 || ny < 0 || nx == m || ny == n || visited[nx][ny])
            {
                continue;
            }
            char c = board[nx][ny];
            if (t->tries.find(c) == t->tries.end())
            {
                continue;
            }
            Trie *next = t->tries[c];
            recursive(board, visited, ans, next, s + c, nx, ny);
            if (next->empty())
            {
                t->remove(c);
            }
        }
        visited[x][y] = false;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n));
        vector<string> ans;
        unordered_set<string> set;
        t = new Trie();

        for (int i = 0; i < words.size(); i++)
        {
            t->parse(words[i]);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c = board[i][j];
                if (t->tries.find(c) != t->tries.end())
                {
                    string s = {c};
                    recursive(board, visited, set, t->tries[c], s, i, j);
                }
            }
        }

        for (auto &&it : set)
        {
            ans.push_back(it);
        }
        return ans;
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
        {'a', 'b'}};
    words = vector<string>{"ab"};
    s.findWords(board, words);
}