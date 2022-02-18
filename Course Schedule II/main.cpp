#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isCyclic(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &rec, int node)
    {
        if (rec[node]) return true;
        if (visited[node]) return false;
        
        rec[node] = true;
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (isCyclic(graph, visited, rec, graph[node][i]))
                return true;
        }
        rec[node] = false;

        return false;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &rs, int node)
    {
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (!visited[graph[node][i]])
            {
                dfs(graph, visited, rs, graph[node][i]);
            }
        }
        rs.push_back(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans = vector<int>();
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        vector<vector<int>> graphOut = vector<vector<int>>(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool> visited = vector<bool>(numCourses, false);
        vector<bool> rec = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (isCyclic(graph, visited, rec, i))
                    return ans;
            }
        }

        visited = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                dfs(graph, visited, ans, i);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> pre = {{1, 0}, {0, 1}};
    s.findOrder(2, pre);
}