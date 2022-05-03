/*
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
 

Constraints:

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int recursive(int node, int mask, vector<vector<int>>& graph) {
        if (dp[node][mask] != 0) {
            return dp[node][mask];
        }
        if ((mask & (mask - 1)) == 0) {
            return 0;
        }
        dp[node][mask] = INT_MAX - 1;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int neighbor = graph[node][i];
            if ((mask & (1 << neighbor)) != 0) {
                int alreadyVisited = recursive(neighbor, mask, graph);
                int firstTime = recursive(neighbor, mask ^ (1 << node), graph);
                int better = min(alreadyVisited, firstTime);
                
                dp[node][mask] = min(dp[node][mask], better + 1);
            }
        }
        
        return dp[node][mask];
    } 

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // int ans = INT_MAX;
        // int mask = (1 << graph.size()) - 1;
        // dp = vector<vector<int>>(graph.size(), vector<int>(mask + 1));
        // for (int i = 0; i < graph.size(); i++)
        // {
        //     ans = min(ans, recursive(i, mask, graph));
        // }
        // return ans;
        if (graph.size() == 1) return 0;

        int ans = 1;
        int endingMask = (1 << graph.size()) - 1;
        vector<vector<bool>> visited = vector<vector<bool>>(graph.size(), vector<bool>(endingMask + 1, false));
        queue<vector<int>> q;
        for (int i = 0; i < graph.size(); i++)
        {
            q.push({i, 1 << i});
        }
        
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                vector<int> state = q.front();
                int node = state[0];
                int mask = state[1];
                q.pop();

                if (visited[node][mask]) continue;
                visited[node][mask] = true;

                if (mask == endingMask) {
                    return ans;
                }

                for (int j = 0; j < graph[node].size(); j++)
                {
                    q.push({graph[node][j], mask | (1 << graph[node][j])});
                }
                
            }
            ans++;
        }

        return -1;
    }
};