
/*
You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
The student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Return true if the student is eligible for an attendance award, or false otherwise.

 

Example 1:

Input: s = "PPALLP"
Output: true
Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.
Example 2:

Input: s = "PPALLL"
Output: false
Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.
 

Constraints:

1 <= s.length <= 1000
s[i] is either 'A', 'L', or 'P'.
*/

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int consecutive = 0;
        int absent = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
            {
                absent++;
                if (absent == 2)
                    return false;
            }

            if (s[i] != 'L')
            {
                consecutive = 0;
            }
            else
            {
                consecutive++;
                if (consecutive == 3)
                    return false;
            }
        }

        return true;
    }

    struct Node
    {
        int id;
        int dist;
        Node(int id, int dist)
        {
            this->id = id;
            this->dist = dist;
        }
    };
    struct CompareNode
    {
        bool operator()(Node v1, Node v2)
        {
            return v1.dist < v2.dist;
        }
    };

    vector<int> dijkstra(map<int, vector<vector<int>>> m, bool visited[], int n, int k)
    {
        vector<int> dist(n + 1);
        priority_queue<Node, vector<Node>, CompareNode> q;
        for (int i = 1; i <= n; i++)
        {
            dist[i] = INT32_MAX;
        }
        q.push(Node(k, 0));
        dist[k] = 0;
        while (q.size() > 0)
        {
            Node node = q.top();
            q.pop();
            visited[node.id] = true;

            if (dist[node.id] < node.dist)
                continue;
            if (m.find(node.id) == m.end())
                continue;

            vector<vector<int>> edges = m[node.id];
            for (int i = 0; i < edges.size(); i++)
            {
                int target = edges[i][0];
                int w = edges[i][1];
                int newDist = dist[node.id] + w;

                if (newDist < dist[target])
                {
                    dist[target] = newDist;
                    q.push(Node(target, dist[target]));
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        bool visited[n + 1];
        map<int, vector<vector<int>>> m;
        for (int i = 0; i <= n; i++)
        {
            visited[i] = false;
        }

        for (int i = 0; i < times.size(); i++)
        {
            int source = times[i][0];
            int target = times[i][1];
            int w = times[i][2];
            if (m.find(source) == m.end())
            {
                m.insert(pair<int, vector<vector<int>>>(source, vector<vector<int>>()));
            }

            m[source].push_back(vector<int>{target, w});
        }

        vector<int> result = dijkstra(m, visited, n, k);

        int time = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                return -1;
            if (i != k)
                time = max(time, result[i]);
        }

        return time;
    }

};

int main()
{
    Solution s;

    // vector<vector<int>> times{
    //     vector<int>{1, 2, 1},
    //     vector<int>{2, 3, 2},
    //     vector<int>{1, 3, 2},
    // };

    vector<vector<int>> times{
        vector<int>{1, 2, 1},
        vector<int>{2, 1, 3},
    };

    // vector<vector<int>> times{
    //     vector<int>{1, 2, 1},
    // };
    s.networkDelayTime(times, 2, 2);
}