/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> group;
    vector<int> rank;
    int count;
public:
    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++)
        {
            group[i] = i;
        }
        count = size;
    }

    int find(int node) {
        if (node == group[node]) {
            return node;
        }
        group[node] = find(group[node]);
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
    void recursive(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (!visited[j] && isConnected[i][j]) {
                recursive(isConnected, visited, j);
            }

        }
        
    }

    int dfs(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited = vector<bool>(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) {
                continue;
            }
            count++;
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j]) {
                    recursive(isConnected, visited, i);
                }
            }
        }
        
        return count;
    }

    int unionFind(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf = UnionFind(n);
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j]) {
                    if (uf.join(i, j)) {
                        ans--;
                    }
                }
            }
            
        }
        return ans;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        return unionFind(isConnected);      
    }
};
