/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m = 10e4 + 1;
public:
    int jump(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(), m);
        dp[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++)
            {
                dp[i] = min(dp[i + j] + 1, dp[i]);
            }
        }
        
        return dp[0];
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>{2,3,1,1,4};
    s.jump(nums);
}