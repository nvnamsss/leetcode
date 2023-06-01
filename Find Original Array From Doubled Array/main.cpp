#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1) {
            return {};
        }
        unordered_map<int, int> m;
        for (int i = 0; i < changed.size(); i++)
        {
            m[changed[i]]++;
        }
        int size = changed.size() / 2;
        vector<int> ans = {};        
        for (int i = 0; i < changed.size() && ans.size() < size; i++)
        {
            int v = changed[i];
            int m2 = v * 2;
            int d2 = v == 0 ? 0 : v%2 == 1 ? -1 : v / 2;
        
            if (m[v] == 0 || (m[m2] ==0 && m[d2] == 0)) {
                return {};
            }

            if (m[m2] > m[d2]) {
                m[m2]--;
                ans.push_back(v);
            } else {
                m[d2]--;
                ans.push_back(d2);
            }

            m[v]--;
        }

        return ans;
    }
};

void print(vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main() {
    Solution s;
    vector<int> changed = {1,3,4,6,2,8};
    vector<int> ans = s.findOriginalArray(changed);
    print(ans);

    changed = {0,0,0,0};
    ans = s.findOriginalArray(changed);
    print(ans);

    changed = {6,3,0,1};
    ans = s.findOriginalArray(changed);
    print(ans);

    changed = {3,1};
    ans = s.findOriginalArray(changed);
    print(ans);

    changed = {0,0,3};
    ans = s.findOriginalArray(changed);
    print(ans);
}