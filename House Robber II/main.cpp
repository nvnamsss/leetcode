#include <bits/stdc++.h>
using namespace std;

class Solution {
    int robInRange(vector<int>& nums, int from, int to) {
        int cur = 0;
        int prev = 0;
        for (int i = from; i < to; i++)
        {
            int m = max(cur, prev + nums[i]);
            prev = cur;
            cur = m;
        }
        
        return max(cur, prev);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(robInRange(nums, 0, nums.size() - 1), robInRange(nums, 1, nums.size()));
    }
};