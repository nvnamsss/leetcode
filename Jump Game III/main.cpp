#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        vector<bool> visited = vector<bool>(arr.size(), false);
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int index = q.front();
            visited[index] = true;
            q.pop();
            if (arr[index] == 0)
            {
                return true;
            }
            if (index + arr[index] < arr.size() && !visited[index + arr[index]])
            {
                q.push(index + arr[index]);
            }
            if (index - arr[index] >= 0 && !visited[index - arr[index]])
            {
                q.push(index - arr[index]);
            }
        }

        return false;
    }
};