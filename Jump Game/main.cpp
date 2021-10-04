#include <bits/stdc++.h>
using namespace std;

class Solution {
    void recursive(vector<int>& nums, vector<int>& dp, int index) {
        if (dp[index] != -1) return;
        dp[index] = 0;

        for (int i = 1; i <= nums[index]; i++)
        {
            recursive(nums, dp, index + i);
            if (dp[index + i] == 1) {
                dp[index] = 1;
                return;
            }
        }
        
    }
public:
    bool canJump(vector<int>& nums) {
        bool rs =false;
        int required = 1;
        for (int loop = nums.size() - 2; loop >= 0; loop--)
        {
            if (nums[loop] >= required)
            {
                required = 1;
            }
            else{
                required += 1;
            }
        }

        if (required == 1)
        {
            rs = true;
        }
        return rs;

        vector<int> dp = vector<int>(nums.size(), -1);
        dp[nums.size() - 1] = 1;
        
        recursive(nums, dp, 0);
        return dp[0] == 1;
    }
};