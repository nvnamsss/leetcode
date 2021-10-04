#include <bits/stdc++.h>
using namespace std;

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
class CustomFunction
{
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};
class Solution
{
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        vector<vector<int>> rs;
        // symetry
        int x = 1;
        int y = 1;
        bool symmetry = customfunction.f(1, 10) == customfunction.f(10, 1);
        int v = 0;

        bool keep = true;
        while (keep)
        {
            while ((v = customfunction.f(x, y)) <= z)
            {
                cout << "x: " << x << " y: " << y << endl;
                if (v == z)
                    rs.push_back(vector<int>{x, y});
                x++;
            }
            x = 1;
            y++;
            if (customfunction.f(x, y) > z)
            {
                keep = false;
            }
        }

        return rs;
    }
    
    void minReorderDfs(vector<vector<int>>& adjacency, vector<bool>& visited, int k, int &c) {
        visited[k] = true;
        vector<int> edges = adjacency[k];
        // int change = 0;

        for (auto v : edges)
        {
            int target = abs(v);
            if (!visited[target]){
                if (v > 0) c++;            
                minReorderDfs(adjacency, visited, target, c);
            }
  
        }
        // return change;
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        int rs = 0;
        vector<vector<int>> adjacency(n);
        vector<bool> visited(n, 0);
        int size = connections.size();

        // for (int i = 0; i < n; i++)
        // {
        //     visited[i] = false;
        // }
        
        for (int i = 0; i < size; i++)
        {
            adjacency[connections[i][0]].push_back(connections[i][1]);
            adjacency[connections[i][1]].push_back(-connections[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) minReorderDfs(adjacency, visited, i, rs);
        }
        
        // rs = minReorderDfs(adjacency, visited, 0);
        return rs;
    }
};

int main() {
    Solution s;
    vector<vector<int>> connections{
        vector<int>{0,1},
        vector<int>{1,3},
        vector<int>{2,3},
        vector<int>{4,0},
        vector<int>{4,5}
    };
    s.minReorder(6, connections);
}