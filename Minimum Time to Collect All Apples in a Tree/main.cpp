/*
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

 

Example 1:


Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
Example 2:


Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
Example 3:

Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0
 

Constraints:

1 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai < bi <= n - 1
fromi < toi
hasApple.length == n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& hasApple, int node, int step) {
        int ans = 0;
        if (hasApple[node]) {
            ans = step;
            step = 0;
        }
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int n = graph[node][i];
            if (visited[n]) {
                continue;
            }
            int v = dfs(graph, visited, hasApple, n, step + 1);
            if (v > 0) {
                ans += v + 1;
                step = 0;
            }
        }
        visited[node] = false;

        return ans;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
        vector<bool> visited = vector<bool>(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        return dfs(graph, visited, hasApple, 0, 0);
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> apple = {false,false,true,false,false,true,false};
    cout << s.minTime(7, graph, apple) << endl;

    apple = {false,false,true,false,true,true,false};
    cout << s.minTime(7, graph, apple) << endl;

    apple = {false,true,false,false,true,true,false};
    cout << s.minTime(7, graph, apple) << endl;


    graph = {{0,2},{0,3},{1,2}};
    apple = {false, true, false, false};
    cout << s.minTime(4, graph, apple) << endl;
}