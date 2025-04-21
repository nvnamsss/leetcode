#include <bits/stdc++.h>
using namespace std;

class Comparer
{
public:
    bool operator()(string a, string b)
    {
        return a.compare(b) > 0;
    }
};

class Solution
{
    bool dfs(unordered_map<string, vector<string>> &graph, unordered_map<string, vector<bool>> &visited,
             vector<string> &ans, string cur, int tickets, int count)
    {
        vector<string> edges = graph[cur];
        ans.push_back(cur);

        if (tickets == count)
        {
            return true;
        }


        for (int i = 0; i < edges.size(); i++)
        {
            string next = edges[i];
            if (visited[cur][i]) {
                continue;
            }
            visited[cur][i] = true;

            if (dfs(graph, visited, ans, next, tickets, count + 1))
            {
                return true;
            }
            visited[cur][i] = false;
        }
        ans.pop_back();

        return false;
    }

    vector<string> usingDfs(vector<vector<string>> &tickets)
    {
        int n = tickets.size();
        unordered_map<string, vector<string>> graph;
        unordered_map<string, vector<bool>> visited;
        for (int i = 0; i < tickets.size(); i++)
        {
            graph[tickets[i][0]].push_back(tickets[i][1]);
            visited[tickets[i][0]].push_back(false);
        }

        for (auto &&it : graph)
        {
            sort(it.second.begin(), it.second.end());
        }

        vector<string> ans;
        dfs(graph, visited, ans, "JFK", n, 0);
        return ans;
    }

    vector<string> usingQueue(vector<vector<string>> &tickets)
    {
        unordered_map<string, priority_queue<string, vector<string>, Comparer>> graph;
        for (int i = 0; i < tickets.size(); i++)
        {
            graph[tickets[i][0]].push(tickets[i][1]);
        }

        vector<string> ans;
        string current = "JFK";
        while (current != "")
        {
            ans.push_back(current);
            string next = "";
            // simulate all path
            // find the good path
            // apply
            // 1 2 3 -> 2 3 1
            // snapshot[k] = {n, t}
            if (!graph[current].empty())
            {
                next = graph[current].top();
                graph[current].pop();
            }

            current = next;
        }

        return ans;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        return usingDfs(tickets);
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
    // string a = "JFK";
    // string b = "SFO";
    // cout << a.compare(b) << endl;

    tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}, {"JFK", "ABC"}, {"SJC", "SFO"}, {"SFO", "LHR"}, {"LHR", "ABC"}, {"ABC", "JFK"}};
    ans = s.findItinerary(tickets);
    print(ans);

    tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    ans = s.findItinerary(tickets);
    print(ans);
}