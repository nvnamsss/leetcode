/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isCircle(vector<unordered_set<int>>& graph, vector<bool>& visited, pair<int, int>& banned, vector<int>& circleList, int node, int lastNode) {
        if (visited[node]) {
            return true;
        }

        visited[node] = true;
        bool ans = false;
        circleList.push_back(node);

        for (auto&& nextNode : graph[node]) {
            if (nextNode == lastNode) {
                continue;
            }

            if ((node == banned.first && nextNode == banned.second) || (node == banned.second && nextNode == banned.first)) {
                continue;
            }
            ans = ans || isCircle(graph, visited, banned, circleList, nextNode, node);
        }
 
        if (!ans) {
            circleList.pop_back();
        }
        visited[node] = false;
        return ans;
    }

    string encode(int a, int b) {
        return to_string(a) + "_" + to_string(b);
    }
    void print(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<bool> visited = vector<bool>(n);
        vector<unordered_set<int>> graph = vector<unordered_set<int>>(n);
        for (int i = 0; i < n; ++i) {
            int from = edges[i][0] - 1;
            int to = edges[i][1] - 1;
            
            graph[from].insert(to);
            graph[to].insert(from);
        }

        vector<int> circleList;
        pair<int, int> p = {-1, -1};
        for (int i = 0; i < n; ++i) {
            bool circle = isCircle(graph, visited, p, circleList, i, -1);
            if (circle) {
                break;
            }
        }
        
        print(circleList);
        vector<int> ans = {0, 0};
        unordered_set<string> possibilities;
        for (int i = 0; i < circleList.size(); ++i) {
            int from = circleList[i];
            vector<int> tmp;
            for (int j = i + 1; j < circleList.size(); ++j) {
                int to = circleList[j];
                p = {from, to};
                int k = 0;
                for (; k < circleList.size(); ++k) {
                    if (k != i && k != j) {
                        break;
                    }
                }

                if (graph[from].count(to) && !isCircle(graph, visited, p, tmp, k, -1)) {
                    possibilities.insert(encode(from + 1, to + 1));
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            int from = edges[i][0];
            int to = edges[i][1];
            string c1 = encode(from, to);
            string c2 = encode(to, from);
            if (possibilities.find(c1) != possibilities.end() || possibilities.find(c2) != possibilities.end()) {
                return {from, to};
            }
        }   

        return {-1, -1};
    }
};

int main() {
    Solution s;

}