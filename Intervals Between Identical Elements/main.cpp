#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> getDistances(vector<int> &arr)
    {
        vector<long long> ans = vector<long long>(arr.size(), 0);
        unordered_map<int, vector<long long>> m;
        for (int i = 0; i < arr.size(); i++)
        {
            if (m.find(arr[i]) == m.end())
            {
                m.insert({arr[i], vector<long long>(5, 0)});
                m[arr[i]][4] = i;
            }
            m[arr[i]][0] = 0;
            m[arr[i]][1]++;
            m[arr[i]][2] = 0;
            m[arr[i]][3] += i - m[arr[i]][4];
        }

        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]][3] -= m[arr[i]][1] * (i - m[arr[i]][4]);
            m[arr[i]][2] += m[arr[i]][0] * (i - m[arr[i]][4]);

            m[arr[i]][0]++;
            m[arr[i]][1]--;
            m[arr[i]][4] = i;
            ans[i] = m[arr[i]][3] + m[arr[i]][2];
        }

        return ans;
    }
};

void print(vector<long long> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    Solution s;
    vector<int> arr = {2, 1, 3, 1, 2, 3, 3};
    vector<long long> rs = s.getDistances(arr);
    print(rs);
    arr = {10,5,10,10};
    rs = s.getDistances(arr);
    print(rs);
    
}