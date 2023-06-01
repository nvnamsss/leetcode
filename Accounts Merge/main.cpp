/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.



Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]


Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j] <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> group;
    vector<int> rank;

public:
    UnionFind(int size)
    {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++)
        {
            group[i] = i;
        }
    }

    int find(int node)
    {
        if (group[node] != node)
        {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2)
    {
        int group1 = find(node1);
        int group2 = find(node2);

        if (group1 == group2)
        {
            return false;
        }

        if (rank[node1] > rank[node2])
        {
            group[group2] = group1;
        }
        else if (rank[node1] < rank[node2])
        {
            group[group1] = group2;
        }
        else
        {
            group[group2] = group1;
            rank[group1]++;
        }
        return true;
    }
};

class Solution
{
    void dfs(vector<string> &rs, unordered_map<string, vector<string>> &graph, unordered_set<string> &visited, string node)
    {
        visited.insert(node);
        rs.push_back(node);
        vector<string> paths = graph[node];
        for (int i = 0; i < paths.size(); i++)
        {
            if (!visited.count(paths[i]))
            {
                dfs(rs, graph, visited, paths[i]);
            }
        }
    }
    vector<vector<string>> recursive(vector<vector<string>> &accounts)
    {
        vector<string> v;
        vector<vector<string>> result;
        unordered_set<string> visited;
        unordered_map<string, vector<string>> graph;

        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                for (int k = j + 1; k < accounts[i].size(); k++)
                {
                    graph[accounts[i][j]].push_back(accounts[i][k]);
                    graph[accounts[i][k]].push_back(accounts[i][j]);
                }
            }
        }

        for (int i = 0; i < accounts.size(); i++)
        {
            if (!visited.count(accounts[i][1]))
            {
                vector<string> subset = {accounts[i][0]};
                dfs(subset, graph, visited, accounts[i][1]);
                sort(subset.begin() + 1, subset.end());
                result.push_back(subset);
            }
        }

        return result;
    }

    vector<vector<string>> unionFind(vector<vector<string>> &accounts)
    {
        vector<vector<string>> result;
        UnionFind uf = UnionFind(accounts.size());
        unordered_map<int, vector<int>> m;

        for (int i = 0; i < accounts.size(); i++)
        {
            vector<string> ai = accounts[i];
            unordered_set<string> s;
            for (int m = 1; m < ai.size(); m++)
            {
                s.insert(ai[m]);
            }

            for (int j = i + 1; j < accounts.size(); j++)
            {
                if (accounts[i][0] == accounts[j][0])
                {

                    for (int m = 1; m < accounts[j].size(); m++)
                    {
                        if (s.find(accounts[j][m]) != s.end())
                        {
                            uf.join(i, j);
                        }
                    }
                }
            }
        }

        unordered_map<int, unordered_set<string>*> ms;
        for (int i = 0; i < accounts.size(); i++)
        {
            int g = uf.find(i);
            if (!ms[g]) {
                ms[g] = new unordered_set<string>();
            }
            unordered_set<string>* s = ms[g];
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (s->find(accounts[i][j]) == s->end())
                {
                    s->insert(accounts[i][j]);
                }
            }
        }

        for (auto &&v : ms)
        {
            vector<string> s = {accounts[v.first][0]};
            unordered_set<string>* ss = v.second;
            s.insert(s.end(), ss->begin(), ss->end());
            sort(s.begin() + 1, s.end());
            result.push_back(s);
        }
        return result;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        return recursive(accounts);
    }
};

int main()
{
    Solution s;
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};
    s.accountsMerge(accounts);
};