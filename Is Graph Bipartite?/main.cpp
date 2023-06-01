#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool BFSApproach(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> colors = vector<int>(v, -1);

        for (int i = 0; i < v; i++)
        {
            if (colors[i] == -1)
            {
                queue<int> q;
                colors[i] = 0;
                q.push(i);

                while (!q.empty())
                {
                    int count = q.size();
                    for (int i = 0; i < count; i++)
                    {
                        int node = q.front();
                        q.pop();

                        for (int j = 0; j < graph[node].size(); j++)
                        {
                            int nextnode = graph[node][j];
                            if (colors[nextnode] == -1)
                            {
                                colors[nextnode] = 1 - colors[node];
                                q.push(graph[node][j]);
                            }
                            else if (colors[nextnode] == colors[node])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        return BFSApproach(graph);
    }
};