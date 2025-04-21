/*
There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. If it is impossible to connect all the n cities, return -1,

The cost is the sum of the connections' costs used.



Example 1:


Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.
Example 2:


Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.


Constraints:

1 <= n <= 104
1 <= connections.length <= 104
connections[i].length == 3
1 <= xi, yi <= n
xi != yi
0 <= costi <= 105
*/

#include <bits/stdc++.h>
using namespace std;
class Comparer
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
};

class UnionFind
{
    vector<int> rank;
    vector<int> group;

public:
    UnionFind(int n)
    {
        rank = vector<int>(n);
        group = vector<int>(n);
        for (int i = 0; i < size; i++)
        {
            group[i] = i;
        }
    }

    int find(int node)
    {
        while (node != this->group[node])
        {
            this->group[node] = this->group[this->group[node]];
            node = this->group[node];
        }
        return node;
    }

    bool join(int a, int b)
    {
        int groupA = group[a];
        int groupB = group[b];
        if (groupA == groupB)
        {
            return false;
        }

        if (rank[groupA] > rank[groupB])
        {
            rank[groupB] = rank[groupA];
        }
        else if (rank[groupA] < rank[groupB])
        {
            group[groupB] = group[groupA];
        }
        else
        {
            group[groupB] = group[groupA];
            ++rank[groupA];
        }
        return true;
    }
};

class Solution
{
    void print(vector<vector<int>> &arr)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            cout << arr[i][2] << " ";
        }
        cout << endl;
    }

    bool isCyclic(vector<vector<int>> &graph, vector<bool> &visited, int node, int lastNode)
    {
        if (visited[node])
        {
            return true;
        }

        visited[node] = true;
        bool ans = false;
        for (int i = 0; i < graph[node].size(); ++i)
        {
            int nextNode = graph[node][i];
            if (nextNode == lastNode)
            {
                continue;
            }
            ans = ans || isCyclic(graph, visited, nextNode, node);
        }

        visited[node] = false;
        return ans;
    }

public:
    int minimumCost(int n, vector<vector<int>> &connections)
    {
        sort(connections.begin(), connections.end(), Comparer());
        print(connections);
        UnionFind u = UnionFind(n);
        int ans = 0;
        int edgeCount = 0;

        for (int i = 0; i < connections.size(); ++i)
        {
            int vf = connections[i][0] - 1;
            int vt = connections[i][1] - 1;
            int w = connections[i][2];
            if (u.find(vf) == u.find(vt))
            {
                continue;
            }
            ans += w;
            edgeCount++;
            ans += w;
        }

        return edgeCount == n - 1 ? ans : -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> connections = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    cout << s.minimumCost(3, connections) << endl;

    connections = {{1, 2, 3}, {3, 4, 4}};
    cout << s.minimumCost(4, connections) << endl;
}