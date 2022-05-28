/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.



Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.


Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Node
    {
        int id;
        int dist;
        Node(int id, int dist)
        {
            this->id = id;
            this->dist = dist;
        }
    };
    struct CompareNode
    {
        bool operator()(Node v1, Node v2)
        {
            return v1.dist < v2.dist;
        }
    };

    vector<vector<int>> dijktra(vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int n, int node, int k)
    {
        vector<vector<int>> distances = vector<vector<int>>(n + 1, {INT32_MAX, 0});
        priority_queue<Node, vector<Node>, CompareNode> pq;
        pq.push(Node(node, 0));
        distances[node] = {0, 0};
        while (!pq.empty())
        {
            Node node = pq.top();
            pq.pop();
            visited[node.id] = true;
            vector<pair<int, int>> edges = graph[node.id];
            if (distances[node.id][1] > k)
            {
                continue;
            }
            for (int i = 0; i < edges.size(); i++)
            {
                int target = edges[i].first;
                int w = edges[i].second;

                int newDistance = distances[node.id][0] + w;
                if (newDistance < distances[target][0])
                {
                    distances[target][0] = newDistance;
                    distances[target][1] = distances[node.id][1] + 1;
                    pq.push(Node(target, newDistance));
                }
            }
        }

        return distances;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> graph = vector<vector<pair<int, int>>>(n);
        vector<bool> visited = vector<bool>(n);
        for (int i = 0; i < flights.size(); i++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            graph[from].push_back({to, cost});
        }

        vector<vector<int>> costs = dijktra(graph, visited, n, src, k);

        if (!visited[dst])
        {
            return -1;
        }
        return costs[dst][0];
    }
};