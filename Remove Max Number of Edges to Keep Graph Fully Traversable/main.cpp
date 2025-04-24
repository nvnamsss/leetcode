#include <bits/stdc++.h>
using namespace std;

class Comparer {
public:
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};

class Solution {
    int dfs(vector<unordered_set<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        int ans = 1;
        for (auto next : graph[node]) {
            if (visited[next]) {
                continue;
            }
            ans += dfs(graph, visited, next);
        }

        return ans;
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graphAlice(n), graphBob(n);
        vector<bool> visitedAlice(n), visitedBob(n);
        int edgeAlice = 0, edgeBob = 0;
        int nAlice = n - 1, nBob = n - 1;

        for (int i = 0; i < edges.size(); ++i) {
            int type = edges[i][0];
            int from = edges[i][1] - 1;
            int to = edges[i][2] - 1;

            if (type == 3) {
                if (!graphAlice[from].count(to)) {
                    graphAlice[from].insert(to);
                    graphAlice[to].insert(from);
                }

                if (!graphBob[from].count(to)) {
                    graphBob[from].insert(to);
                    graphBob[to].insert(from);
                }

                edgeAlice++;
                edgeBob++;
            } else if (type == 1) {
                if (!graphAlice[from].count(to)) {
                    graphAlice[from].insert(to);
                    graphAlice[to].insert(from);
                }
                edgeAlice++;
            } else if (type == 2) {
                if (!graphBob[from].count(to)) {
                    graphBob[from].insert(to);
                    graphBob[to].insert(from);
                }
                edgeBob++;
            }
        }

        int vA = dfs(graphAlice, visitedAlice, 0);
        int vB = dfs(graphBob, visitedBob, 0);
        if (vA != n || vB != n) {
            return -1;
        }

        return (edgeAlice - nAlice) + (edgeBob - nBob);
    }
};