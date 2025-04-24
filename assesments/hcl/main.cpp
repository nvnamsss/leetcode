/**
 * node1: com
 * edge1: mail -> node2
 * node2: mail.com
 * 
 * approach:
 * - build the graph
 * - iterate over the cpdomains, split the cpdomain to root node, edges. Then traverse over the graph, increase the visited time
 * - iterate over the graph again, collect the answer
 * 
 * time complexity: each domain have length m, and there are n domains, so the time complexity is O(n*m)
 * space complexity: O(k), k is the unique domains
 */
#include <bits/stdc++.h>
using namespace std;

class Node {
    // edges
    unordered_map<string, Node*> edges;
    int visited;

public:
    Node() {
        edges = unordered_map<string, Node*>();
        visited = 0;
    }

    void build(vector<string>& subdomains, int visitedTime) {
        Node* current = this;
        for (int i = subdomains.size() - 1; i >= 0; --i) {
            string domain = subdomains[i];
            // check duplicate
            if (current->edges.find(domain) == current->edges.end()) {
                current->edges[domain] = new Node();
            }

            current = current->edges[domain];
            current->visited += visitedTime;
        }
    }

    vector<string> getVisitedTime() {
        vector<string> ans;
        queue<pair<Node*, string>> q;
        // q.push({this, ""});
        for (auto &&it : edges) {
            // dfs(it.second, ans, )
            q.push({it.second, it.first});
        }
                
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; ++i) {
                pair<Node*, string> p = q.front();
                q.pop();

                string visitedTime = to_string(p.first->visited);
                ans.push_back(visitedTime + " " + p.second);

                for (auto &&it : p.first->edges) {
                    // dfs(it.second, ans, )
                    q.push({it.second, it.first + "." + p.second});
                }
            }
        }

        return ans;
    }

};

class Solution {
    vector<string> split(const string& str, const string& delim)
    {
        vector<string> result;
        size_t start = 0;

        for (size_t found = str.find(delim); found != string::npos; found = str.find(delim, start))
        {
            result.emplace_back(str.begin() + start, str.begin() + found);
            start = found + delim.size();
        }
        if (start != str.size())
            result.emplace_back(str.begin() + start, str.end());
        return result;      
    }

public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // build the graph
        // node, list of edges
        Node* root = new Node();
        // unordered_map<string, vector<string>> graph;

        for (int i = 0 ; i < cpdomains.size(); ++i) {
            vector<string> splitted = split(cpdomains[i], " ");
            int visitedTime = stoi(splitted[0]);

            vector<string> subdomains = split(splitted[1], ".");

            root->build(subdomains, visitedTime);
        }


        vector<string> ans = root->getVisitedTime();
        return ans;
    }
    
};

int main() {
    Solution s;
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> ans = s.subdomainVisits(cpdomains);
    for (auto &&it : ans) {
        cout << it << endl;
    }

    // [“901 mail.com”,”50 yahoo.com”,”900 google.mail.com”,”5 wiki.org”,”5 org”,”1 intel.mail.com”,”951 com”]
}