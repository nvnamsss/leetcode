#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(unordered_map<string, vector<string>> &graph, unordered_map<string, unordered_map<string, bool>> &visited,
             vector<string> &ans, string department, int tickets, int count)
    {
        vector<string> edges = graph[department];
        ans.push_back(department);

        if (tickets == count)
        {
            return true;
        }

        for (int i = 0; i < edges.size(); i++)
        {
            if (visited[department][edges[i]])
            {
                visited[department][edges[i]] = true;
                if (dfs(graph, visited, ans, edges[i], tickets, count + 1))
                {
                    return true;
                }
                visited[department][edges[i]] = false;
            }
        }
        ans.pop_back();

        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        int n = tickets.size();
        unordered_map<string, vector<string>> graph;
        unordered_map<string, unordered_map<string, bool>> visited;
        for (int i = 0; i < tickets.size(); i++)
        {
            graph[tickets[i][0]].push_back(tickets[i][1]);
            visited[tickets[i][0]][tickets[i][1]] = false;
        }

        for (auto &&it : graph)
        {
            sort(it.second.begin(), it.second.end());
        }

        vector<string> ans;
        dfs(graph, visited, ans, "JFK", n, 0);
        return ans;
    }
};

void print(vector<string> &tickets)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        cout << tickets[i] << " ";
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<vector<string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> ans = s.findItinerary(tickets);
    print(ans);
}