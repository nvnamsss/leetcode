#include <bits/stdc++.h>
using namespace std;

class Solution {
    void recursive(vector<vector<int>>& ans, vector<int>& subans, int k, int n, int u, int s) {
        if (subans.size() == k) {
            if (s == n) {
                ans.push_back(subans);
            }
            return;
        }

        for (int i = u; i <= 9; i++)
        {
            subans.push_back(i);
            recursive(ans, subans, k, n , i + 1, s + i);
            subans.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subans;
        recursive(ans, subans, k, n, 0, 0);
        return ans;
    }
};