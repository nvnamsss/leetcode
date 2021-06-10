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

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

using System;
using System.Collections.Generic;
public class Solution
{
    public bool CanFinish(int numCourses, int[][] prerequisites)
    {
        List<List<int>> g = new List<List<int>>();
        for (int loop = 0; loop < numCourses; loop++)
        {
            g.Add(new List<int>());
        }


        for (int loop = 0; loop < prerequisites.Length; loop++)
        {
            int[] pre = prerequisites[loop];
            g[pre[1]].Add(pre[0]);
        }

        bool[] visited = new bool[numCourses];
        bool[] recstack = new bool[numCourses];

        for (int loop = 0; loop < numCourses; loop++)
        {
            if (isCyclic(g, loop, visited, recstack))
            {
                return false;
            }
        }

        return true;
    }

    private bool isCyclic(List<List<int>> graph, int node, bool[] visited, bool[] recstack)
    {
        if (recstack[node]) return true;
        if (visited[node]) return false;

        recstack[node] = true;
        visited[node] = true;

        List<int> adjacents = graph[node];

        for (int loop = 0; loop < adjacents.Count; loop++)
        {
            int i = adjacents[loop];
            if (isCyclic(graph, i, visited, recstack))
            {
                return true;
            }
        }

        recstack[node] = false;
        return false;
    }
}