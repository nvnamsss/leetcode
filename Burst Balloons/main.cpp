/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 500
0 <= nums[i] <= 100

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int recursive(vector<int>& nums, vector<vector<int>>& dp, int l, int r) {
        if (l >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for (int i = l; i < r; i++)
        {
            int coin = recursive(nums, dp, l, i) + recursive(nums, dp, i + 1, r) + nums[l - 1] * nums[i] * nums[r];
            ans = max(ans, coin);
        }
        
        dp[l][r] = ans;
        return dp[l][r];
    }
public:
    int maxCoins(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size() + 2;
        vector<int> coins = vector<int>(n, 1);
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, -1));
        for (int i = 0; i < nums.size(); i++)
        {
            coins[i+1] = nums[i];
        }
        ans = recursive(coins, dp, 1, n -1);       
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 1, 5, 8};

    int rs = s.maxCoins(nums);
    cout << rs << endl;
}