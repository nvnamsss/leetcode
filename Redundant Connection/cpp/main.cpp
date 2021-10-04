/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        bool m[1000][1000];

        unordered_map<int, unordered_set<int>> map;
        unordered_map<int, int> degrees;
        vector<int> rs{0, 0};
        for (int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            if (m[from][to])
            {
                rs[0] = from;
                rs[1] = to;
                return rs;
            }

            m[from][to] = true;
            m[to][from] = true;

            
            // if (map.find(from) == map.end()) {
            //     map.insert(pair<int, unordered_set<int>>(from, unordered_set<int>()));
            // }

            // if (map.find(to) == map.end()) {
            //     map.insert(pair<int, unordered_set<int>>(from, unordered_set<int>()));
            // }

            // if (map[from].find(to) != map[from].end()) {
            //     rs[0] = from;
            //     rs[1] = to;
            //     return rs;
            // }
        }

        return rs;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges{
        vector<int>{1, 2},
        vector<int>{1, 3},
        vector<int>{2, 3}};

    vector<int> rs = s.findRedundantConnection(edges);
    cout << "Result: " << rs[0] << "," << rs[1] << endl;

    edges = vector<vector<int>>{
        vector<int>{1, 2},
        vector<int>{2, 3},
        vector<int>{3, 4},
        vector<int>{1, 4},
        vector<int>{1, 5},
    };

    rs = s.findRedundantConnection(edges);
    cout << "Result: " << rs[0] << "," << rs[1] << endl;

    edges = vector<vector<int>>{
        vector<int>{9, 10},
        vector<int>{5, 8},
        vector<int>{2, 6},
        vector<int>{1, 5},
        vector<int>{3, 8},
        vector<int>{4, 9},
        vector<int>{8, 10},
        vector<int>{4, 10},
        vector<int>{6, 8},
        vector<int>{7, 9},
    };
    rs = s.findRedundantConnection(edges);
    cout << "Result: " << rs[0] << "," << rs[1] << endl;

    return 1;
}