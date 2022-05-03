#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    Graph()
    {
    }
};
class Solution
{
    double solve(unordered_map<string, unordered_map<string, double>> &graph, vector<string> &query)
    {
        if (graph.find(query[0]) == graph.end()) {
            return -1;
        }

        queue<pair<string, double>> q;
        q.push({query[0], 1});
        unordered_set<string> visited;

        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                pair<string, double>p = q.front();
                string node = p.first;
                double val = p.second;

                if (node == query[1]) {
                    return val;
                }

                q.pop();
                visited.insert(node);
                unordered_map<string, double> edges = graph[node];

                for (auto &&it : edges)
                {
                    if (visited.find(it.first) == visited.end()) {
                        q.push({it.first, val * it.second});
                    }
                }
            }
        }

        return -1;
    }   

    double query(unordered_map<string, double> variables, string v1, string v2)
    {
        if (variables.find(v1) == variables.end() || variables.find(v2) == variables.end())
        {
            return -1;
        }

        return variables[v1] / variables[v2];
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, double> variables;
        unordered_map<string, unordered_map<string, double>> graph;
    
        for (int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(solve(graph, queries[i]));
        }
        return ans;
    }
};

int main() {
    Solution s;
}