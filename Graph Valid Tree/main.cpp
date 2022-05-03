/*
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

Example 1:


Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.

*/

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
    }

    int find(int node) {
        if (node != group[node]) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2) {
        int group1 = group[node1];
        int group2 = group[node2];
        if (group1 == group2) {
            return false;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group2] > rank[group1]) {
            group[group1] = group2;
        } else {
            group[group2] = group1;
            rank[group1]++;
        }
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int count = n;
        UnionFind uf = UnionFind(n);
        for (int i = 0; i < edges.size(); i++)
        {  
            if (!uf.join(edges[i][0], edges[i][1])) {
                return false;
            }
            count--;
        }
    
        return count == 1;
    }
};