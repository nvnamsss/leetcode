#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2) return false;
        
        int sumd2 = sum / 2;
        vector<bool> dp = vector<bool>(sumd2 + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sumd2; j >= nums[i]; j--)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        
        return dp[sumd2];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout << s.canPartition(nums) << endl;

    nums = {1,2,3,4,5,6,7};
    cout << s.canPartition(nums) << endl;
}