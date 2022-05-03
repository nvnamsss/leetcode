/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.



Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18


Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.

*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> group;
    vector<int> rank;

public:
    UnionFind(int size)
    {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++)
        {
            group[i] = i;
        }
    }

    int find(int node)
    {
        if (group[node] != node)
        {
            group[node] = find(group[node]);
        }

        return group[node];
    }

    bool join(int node1, int node2)
    {
        int group1 = find(node1);
        int group2 = find(node2);
        if (group1 == group2)
        {
            return false;
        }
        if (rank[group1] > rank[group2])
        {
            group[group2] = group1;
        }
        else if (rank[group1] < rank[group2])
        {
            group[group1] = group2;
        }
        else
        {
            group[group2] = group1;
            rank[group1] += 1;
        }
        return true;
    }
};

class Solution
{
    int distance(int x1, int x2, int y1, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int primOptimal(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<bool> visited = vector<bool>(n);
        vector<int> minDict = vector<int>(n, INT32_MAX);
        int edgesUsed = 0;
        int ans = 0;
        
        while (edgesUsed < n)
        {
            int node = 0;
            int w = INT32_MAX;
            for (int i = 0; i < n; i++)
            {
                if (!visited[node] && w > minDict[i]) {
                    node = i;
                    w= minDict[i];
                }
            }

            visited[node] = true;
            ans += w;
            edgesUsed++;
            for (int i = 0; i < n; i++)
            {
                int d = distance(points[node][0], points[i][0], points[node][1], points[i][1]);
                minDict[i] = d;
            }
        }
        return ans;
    }


    int prim(vector<vector<int>> &points)
    {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited = vector<bool>(n);
        int edgesUsed = 0;
        int ans = 0;

        pq.push({0, 0});
        while (edgesUsed < n)
        {
            pair<int, int> p = pq.top();
            pq.pop();

            int w = p.first;
            int node = p.second;

            if (visited[node])
            {
                continue;
            }

            visited[node] = true;
            ans += w;
            edgesUsed++;
            for (int i = 0; i < n; i++)
            {
                int d = distance(points[node][0], points[i][0], points[node][1], points[i][1]);
                if (!visited[i])
                {
                    pq.push({d, i});
                }
            }
        }
        return ans;
    }

    int kruskal(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 0;
        vector<vector<int>> edges = vector<vector<int>>();
        vector<bool> visited = vector<bool>(n);
        UnionFind uf = UnionFind(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d = distance(points[i][0], points[j][0], points[i][1], points[j][1]);
                edges.push_back({d, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        // minimum spanning tree;
        int edgesUsed = 0;
        int i = 0;
        while (edgesUsed < n - 1)
        {
            if (uf.join(edges[i][1], edges[i][2]))
            {
                edgesUsed++;
                ans += edges[i][0];
            }
            i++;
        }

        return ans;
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        if (points.size() == 1)
            return 0;

        return prim(points);
    }
};

int main()
{
    vector<vector<int>> v = {{2, -3}, {-17, -8}, {13, 8}, {-17, -15}};
    Solution s;
    cout << s.minCostConnectPoints(v) << endl;
}