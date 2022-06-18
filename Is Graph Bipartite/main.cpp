#include <bits/stdc++.h>
using namespace std;
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
    };

    int find(int node){
        if (node != group[node]) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        if (group1 == group2) {
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
class Solution {
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& colors, int node, int color) {
        visited[node] = true;
        colors[node] = color;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            if (!visited[next]) {
                if (!dfs(graph, visited, colors, next, color^1)) {
                    return false;
                }
            } else {
                if (color == colors[next]) {
                    return false;
                }
            }
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors = vector<int>(n, -1);
        vector<bool> visited = vector<bool>(n);

        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && !dfs(graph, visited, colors, i, 0)) {
                return false;
            }
        }
        return true;
    }
};