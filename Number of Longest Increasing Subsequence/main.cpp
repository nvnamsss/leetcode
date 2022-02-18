#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(), 1);
        vector<int> dpcount = vector<int>(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j]) {

                    if (dp[i] <= dp[j]) {
                        dp[i] = dp[j] + 1;
                        dpcount[i] = dpcount[j];
                    } else if (dp[i] == dp[j] + 1) {
                        dpcount[i] += dpcount[j];
                    }
                }
            }
        }
        int m = 0;
        int ans = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            m = max(m, dp[i]);
        }
        
        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i] == m) {
                ans += dpcount[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>{1,3,5,4,7};
    int rs = s.findNumberOfLIS(nums);
    cout << rs << endl;
    nums = vector<int>{2,2,2,2,2};
    s.findNumberOfLIS(nums);
    cout << rs << endl;
}