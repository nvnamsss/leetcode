#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int m = INT32_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            int dif = arr[i] - arr[i - 1];
            if (dif > m) {
                continue;
            }

            if (dif < m) {
                m = dif;
                ans = {};
            }

            ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {4,2,1,3};
    s.minimumAbsDifference(arr);

}