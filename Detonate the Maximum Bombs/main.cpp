/*
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

 

Example 1:


Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.
Example 2:


Input: bombs = [[1,1,5],[10,10,5]]
Output: 1
Explanation:
Detonating either bomb will not detonate the other bomb, so the maximum number of bombs that can be detonated is 1.
Example 3:


Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
Output: 5
Explanation:
The best bomb to detonate is bomb 0 because:
- Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
- Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
- Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
Thus all 5 bombs are detonated.
 

Constraints:

1 <= bombs.length <= 100
bombs[i].length == 3
1 <= xi, yi, ri <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        if (visited[node]) {
            return 0;
        }
        visited[node] = true;
        int ans = 1;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i];
            ans += dfs(graph, visited, nextNode);
        }
        return ans;
    }

    double distance(int x1, int y1, int x2, int y2) {
        double x = pow(x1 - x2, 2);
        double y = pow(y1 - y2, 2);
        return sqrt(x + y);
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        vector<vector<int>> graph = vector<vector<int>>(bombs.size());
        for (int i = 0; i < bombs.size(); i++)
        {
            int xi = bombs[i][0];
            int yi = bombs[i][1];
            int ri = bombs[i][2];

            for (int j = i + 1; j < bombs.size(); j++)
            {
                int xj = bombs[j][0];
                int yj = bombs[j][1];
                int rj = bombs[j][2];

                double d = distance(xi, yi, xj, yj);
                if (d <= ri) {
                    graph[i].push_back(j);
                }

                if (d <= rj) {
                    graph[j].push_back(i);
                }
            }
            
        }

        for (int i = 0; i < bombs.size(); i++)
        {
            vector<bool> visited = vector<bool>(bombs.size());

            int subans = dfs(graph, visited, i);
            ans = max(ans, subans);
        }
        
        return ans;
    }   
};

int main() {
    Solution s;
    vector<vector<int>> bombs = {
        {2,1,3},{6,1,4}
    };
    s.maximumDetonation(bombs);

    bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    s.maximumDetonation(bombs);
}