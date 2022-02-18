
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        queue<int> q;
        vector<bool> visited = vector<bool>(arr.size(), false);
        unordered_map<int, vector<int>> m;
        int ans = 0;
        q.push(0);

        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]].push_back(i);
        }

        while (!q.empty())
        {
            int count = q.size();
            for (int loop = 0; loop < count; loop++)
            {
                int index = q.front();
                q.pop();

                if (index == arr.size() - 1)
                {
                    return ans;
                }

                if (visited[index])
                    continue;
                visited[index] = true;
                if (index > 0)
                {
                    q.push(index - 1);
                }
                q.push(index + 1);

                if (m.count(arr[index]))
                {
                    vector<int> relates = m[arr[index]];
                    for (int i = relates.size() - 1; i >= 0; i--)
                    {
                        if (!visited[relates[i]])
                        {
                            q.push(relates[i]);
                        }
                    }
                    m.erase(arr[index]);
                }
            }

            ans++;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    cout << s.minJumps(arr) << endl;
}