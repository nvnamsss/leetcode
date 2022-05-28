/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 10^5
n - 1 <= connections.length <= 10^5
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& graph, vector<bool>& visited,
    vector<vector<int>>& bridges, vector<int>& low, vector<int>& ids,
    int id, int at, int parent) {
        visited[at] = true;
        low[at] = ids[at] = id++;

        for (int i = 0; i < graph[at].size(); i++)
        {
            int to = graph[at][i];
            if (to == parent) continue;
            if (!visited[to]) {
                dfs(graph, visited, bridges, low, ids, id, to, at);
                low[at] = min(low[at], low[to]);
                if (ids[at] < low[to]) {
                    bridges.push_back({at, to});
                }
            } else {
                low[at] = min(low[at], ids[to]);
            }
        }
        
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph = vector<vector<int>>(n);
        vector<vector<int>> bridges;
        vector<bool> visited = vector<bool>(n);
        vector<int> low = vector<int>(n);
        vector<int> ids = vector<int>(n);
        for (int i = 0; i < connections.size(); i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) {
                dfs(graph, visited, bridges, low, ids, 0, i, -1);
            }
        }
                
        return bridges;
    }
};

int main() {
    Solution s;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> ans = s.criticalConnections(4, connections);
}