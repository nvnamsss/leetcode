#include <bits/stdc++.h>
using namespace std;

class Solution {
    void recursive(vector<vector<int>>& rs, vector<int> sub, int n, int k, int index) {
        if (sub.size() == k) {
            rs.push_back(sub);
            return;
        }
        for (int i = index; i <= n; i++)
        {
            sub.push_back(i);
            recursive(rs, sub, n, k, i + 1);
            sub.pop_back();
        }
        
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> rs;
        recursive(rs, vector<int>{}, n, k, 1);
        return rs;
    }
};