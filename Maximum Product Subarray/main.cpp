#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int dp1 = 1;
        int dp11 = 1;
        int dp2 = 1;
        int dp22 = 1;
        int ans = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0) {
                dp1 = max(dp11 * nums[i], nums[i]);
                dp2 = min(dp22 * nums[i], nums[i]);
            } else {
                dp1 = max(dp22 * nums[i], nums[i]);
                dp2 = min(dp11 * nums[i], nums[i]);
            }

            dp11 = dp1;
            dp22 = dp2;
            ans = max(dp1, ans);
        }
        
        return ans;
    }
};