/*
Question 1:
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

Question 2:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
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

    List<int> rs;
    public int[] FindOrder(int numCourses, int[][] prerequisites)
    {
        rs = new List<int>(numCourses);
        List<List<int>> gr = new List<List<int>>();
        for (int loop = 0; loop < numCourses; loop++)
        {
            gr[loop] = new List<int>();
        }

        for (int loop = 0; loop < prerequisites.Length; loop++)
        {
            int[] pre = prerequisites[loop];
            gr[pre[0]].Add(pre[1]);
        }

        // solve
        bool[] visited = new bool[numCourses];
        for (int loop = 0; loop < numCourses; loop++)
        {
            solve(gr, loop, visited);
        }

        return rs.ToArray();
    }

    private void solve(List<List<int>> gr, int node, bool[] visited)
    {
        List<int> requires = gr[node];
        if (visited[node]) return;

        visited[node] = true;

        if (requires.Count == 0)
        {
            rs.Add(node);
            return;
        }

        for (int loop = 0; loop < requires.Count; loop++)
        {
            solve(gr, requires[loop], visited);
        }

        rs.Add(node);
    }
}