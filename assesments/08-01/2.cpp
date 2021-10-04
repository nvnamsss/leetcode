#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Compare
    {
        bool operator()(vector<int> a, vector<int> b)
        {
            return abs(a[0] - a[1]) < abs(b[0] - b[1]);
        }
    };

public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        vector<pair<int, int>> v;
        for (auto x : costs)
        {
            v.push_back({x[0], x[1]});
        }

        sort(v.begin(), v.end(), cmp);

        vector<pair<int, int>> v1;

        int cost = 0;

        for (int i = 0; i < costs.size() / 2; i++)
        {
            cost += v[i].first;
        }

        for (int i = costs.size() / 2; i < costs.size(); i++)
        {
            cost += v[i].second;
        }

        return cost;
    }

    bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first - b.first < a.second - b.second;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> directions = vector<vector<int>>{
            vector<int>{1, 0},
            vector<int>{-1, 0},
            vector<int>{0, 1},
            vector<int>{0, -1},
        };
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        int rs = -1;
        while (true)
        {
            rs++;
            vector<pair<int, int>> rotten;
            while (!q.empty())
            {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x = p.first + directions[i][0];
                    int y = p.second + directions[i][1];
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    if (grid[x][y] == 1)
                    {
                        rotten.push_back({x, y});
                        grid[x][y] = 2;
                    }
                }
            }

            if (rotten.size() == 0)
                break;
            for (int i = 0; i < rotten.size(); i++)
            {
                q.push(rotten[i]);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return rs;
    }

    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> rs = vector<vector<int>>(n, vector<int>(n, 0));
        vector<pair<int, int>> directions = vector<pair<int, int>>{
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}};
        int m = n * n;
        int d = 0;
        int x = 0;
        int y = 0;

        for (int i = 1; i <= m; i++)
        {
            rs[x][y] = i;
            int xn = x + directions[d].first;
            int yn = y + directions[d].second;
            if (xn < 0 || xn >= n || yn < 0 || yn >= n || rs[xn][yn] != 0)
            {
                d = (d + 1) % 4;
            }

            x = x + directions[d].first;
            y = y + directions[d].second;
        }

        return rs;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> costs{
        vector<int>{10, 20},
        vector<int>{30, 200},
        vector<int>{400, 50},
        vector<int>{30, 20}};

    s.twoCitySchedCost(costs);

    costs = vector<vector<int>>{
        vector<int>{259, 770},
        vector<int>{448, 54},
        vector<int>{926, 667},
        vector<int>{184, 139},
        vector<int>{840, 118},
        vector<int>{577, 469}};
    s.twoCitySchedCost(costs);

    s.generateMatrix(3);
}