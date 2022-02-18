/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
Example 3:

Input: n = 1, edges = []
Output: [0]
Example 4:

Input: n = 2, edges = [[0,1]]
Output: [0,1]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        int height = 0;
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (!visited[graph[node][i]]) {
                height = max(height, 1 + dfs(graph, visited, graph[node][i]));
            }
        }
        
        return height;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph = vector<unordered_set<int>>(n);

        vector<bool> visited = vector<bool>(n, false);
        vector<int> leaves;
        if (n <= 2) {
            vector<int> rs;
            for (int i = 0; i < n; i++)
            {
                rs.push_back(i);
            }
            return rs;
        }

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }    
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            for (int i = 0; i < leaves.size(); i++)
            {
                unordered_set<int> s = graph[leaves[i]];
                for (auto it: s) {
                    graph[it].erase(leaves[i]);
                    if (graph[it].size() == 1) {
                        newLeaves.push_back(it);
                    }
                }
            }
            leaves = newLeaves;
        }
        
        return leaves;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {};
    s.findMinHeightTrees(1, edges);
}