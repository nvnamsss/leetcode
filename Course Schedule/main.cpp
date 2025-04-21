/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dfs(vector<vector<int>> &graph, vector<int> &visited, int node)
    {
        if (visited[node] != 0) {
            return visited[node];
        }

        visited[node] = 1;
        bool ans = true;
        for (size_t i = 0; i < graph[node].size(); i++)
        {
            int able = dfs(graph, visited, graph[node][i]);
            ans = ans && able == 2;
        }

        visited[node] = ans + 1;
        return visited[node];        
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        vector<int> visited = vector<int>(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];

            graph[to].push_back(from);
        }

        for (int i = 0; i < numCourses; i++)
        {
            int state = dfs(graph, visited, i);
            if (state == 1) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> prerequisites = {{1, 0}};

    cout << s.canFinish(2, prerequisites) << endl;
}