/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
 

Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < routes.size(); i++)
        {
            for (int j = 0; j < routes[i].size(); j++)
            {
                graph[routes[i][j]].push_back(i);
            }
        }
        unordered_set<int> visited;
        unordered_set<int> busesCatched;
        queue<int> q;
        q.push(source);
        int ans = 0;
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                int station = q.front();
                q.pop();
                if (station == target) {
                    return ans;
                }
                if (visited.count(station)) {
                    continue;
                }
                visited.insert(station);
                vector<int> buses = graph[station];
                for (int j = 0; j < buses.size(); j++)
                {
                    if (busesCatched.count(buses[j])) {
                        continue;
                    } 
                    busesCatched.insert(buses[j]);
                    for (int k = 0; k < routes[buses[j]].size(); k++)
                    {
                        q.push(routes[buses[j]][k]);
                    }
                    
                }
            }
            ans++;
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> buses = {
        {1,2,7},{3,6,7},
    };
    cout << s.numBusesToDestination(buses, 1, 6) << endl;
}