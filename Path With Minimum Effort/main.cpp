#include <bits/stdc++.h>
using namespace std;

class Cell
{
    public:
    int x;
    int y;
    int difference;
    Cell(int x, int y, int difference)
    {
        this->x = x;
        this->y = y;
        this->difference = difference;
    }
    

};

class Comparator {
public:
    bool operator () (Cell& a, Cell& b) {
        return b.difference < a.difference;
    }
};

class UnionFind {
    vector<int> group;
    vector<int> rank;
public:
    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++)
        {
            group[i] = i;
        }
    }

    int find(int node) {
        if (node != group[node]) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        if (group1 != group2) {
            return false;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group2] = group1;
            rank[group1]++;
        }

        return true;
    }
};

class Solution
{
    vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int recursive(vector<vector<int>> &heights, vector<vector<bool>> &visited, int m, int n, int x, int y, int dif)
    {
        if (x == m - 1 && y == n - 1)
        {
            return dif;
        }
        int ans = INT32_MAX;

        visited[x][y] = true;
        for (int i = 0; i < directions.size(); i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            if (nx < 0 || ny < 0 || nx == m || ny == n || visited[nx][ny])
            {
                continue;
            }
            int d = max(dif, abs(heights[x][y] - heights[nx][ny]));
            int r = recursive(heights, visited, m, n, nx, ny, d);
            ans = min(ans, r);
        }

        visited[x][y] = false;

        return ans;
    }

    // TLE
    int dfs(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n));

        return recursive(heights, visited, m, n, 0, 0, 0);
    }

    int dijkstra(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int columns = heights[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(rows, vector<bool>(columns));
        vector<vector<int>> differenceMatrix(rows, vector<int>(columns, INT_MAX));
        differenceMatrix[0][0] = 0;
        priority_queue<Cell, vector<Cell>, Comparator> pq;

        pq.push(Cell(0, 0, differenceMatrix[0][0]));
        while (!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();

            visited[cur.x][cur.y] = true;
            if (cur.x == rows-1 && cur.y == columns - 1) return cur.difference;
            for (int i = 0; i < directions.size(); i++)
            {
                int nx = cur.x + directions[i][0];
                int ny = cur.y + directions[i][1];
                if (nx < 0 || ny < 0 || nx == rows || ny == columns || visited[nx][ny]) {
                    continue;
                }
                int maxDifference = max(abs(heights[cur.x][cur.y] - heights[nx][ny]), differenceMatrix[cur.x][cur.y]);
                if (maxDifference < differenceMatrix[nx][ny]) {
                    differenceMatrix[nx][ny] = maxDifference;
                    pq.push(Cell(nx,ny, differenceMatrix[nx][ny]));
                }
            }
        }

        return differenceMatrix[rows-1][columns-1];
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        return dijkstra(heights);
    }
};

int main()
{
    Solution s;
    return 0;
}