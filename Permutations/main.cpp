#include <bits/stdc++.h>
using namespace std;

class Solution {
    void swap(vector<int>& v, int a, int b) {
        int t = v[a];
        v[a] = v[b];
        v[b] = t;
    } 
    void recursive(vector<vector<int>>& result, vector<int> sub, vector<int>& nums, int index) {
        if (sub.size() == nums.size()) {
            result.push_back(sub);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums, i, index);
            sub.push_back(nums[index]);
            recursive(result, sub, nums, index + 1);
            sub.pop_back();
            swap(nums, i, index);
        }
        
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        recursive(result, vector<int>{}, nums, 0);
        return result; 
    }
};