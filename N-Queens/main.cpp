#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string gen(int row, int n)
    {
        string s;
        for (int i = 0; i < row; i++)
        {
            s += ".";
        }

        s += "Q";

        for (int i = row + 1; i < n; i++)
        {
            s += ".";
        }

        return s;
    }

    void seal(vector<vector<bool>> &banned, int r, int c, bool v)
    {
        int n = banned.size();
        for (int i = c; i < n; i++)
        {
            banned[r][i] = v;
        }
    
        int x = r;
        int y = c;
        while (x < n && y < n)
        {
            banned[x][y] = v;
            x++;
            y++;
        }
        x = r;
        y = c;
        while (x < n && y >= 0)
        {
            banned[x][y] = v;
            x++;
            y--;
        }
    }

    void recursive(vector<vector<string>> &ans, vector<vector<bool>> &banned, vector<string> &subans,
                   int n, int count)
    {
        if (count == n)
        {
            ans.push_back(subans);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (banned[i][count])
            {
                continue;
            }
            seal(banned, i, count, true);
            subans.push_back(gen(i, n));
            recursive(ans, banned, subans, n, count + 1);
            subans.pop_back();
            seal(banned, i, count, false);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<bool>> banned = vector<vector<bool>>(n, vector<bool>(n));
        vector<string> subans;
        recursive(ans, banned, subans, n, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    s.solveNQueens(4);
}