/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.
*/

#include <bits/stdc++.h>
using namespace std;

class Comparer {
    public:
    bool operator () (pair<double, int>& a, pair<double,int>& b) {
        return a.first < b.first;
    }
};  

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double, int>, vector<pair<double,int>>, Comparer> pq;
        vector<double> dist = vector<double>(n);
        vector<bool> visited = vector<bool>(n);
        vector<unordered_map<int, double>> graph = vector<unordered_map<int, double>>(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            graph[from].insert({to, succProb[i]});
            graph[to].insert({from, succProb[i]});
        }
        
        pq.push({1, start});
        dist[start] = 1;

        while (!pq.empty()) {
            pair<double,int> p = pq.top();
            pq.pop();
            
            if (visited[p.second]) {
                continue;
            }

            dist[p.second] = p.first;
            visited[p.second] = true;
            if (p.second == end) {
                return p.first;
            }

            for (auto&&it : graph[p.second]) 
            {
                int next = it.first;
                double prob = it.second;

                double newProb = p.first * prob;
                if (dist[next] > newProb || visited[next]) {
                    continue;
                }

                pq.push({p.first * prob, next});
            }
        }

        return 0;
    }
};

int main() {

}