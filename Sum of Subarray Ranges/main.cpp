/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(2));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - i - 1; j > 0; j--)
            {
                dp[j][0] = min(dp[j-1][0], nums[i]);
                dp[j][1] = max(dp[j-1][1], nums[i]);
                ans += (dp[j][1] - dp[j][0]);
            }
            dp[0][0] = nums[i];
            dp[0][1] = nums[i];
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.subArrayRanges(nums) << endl;

    nums = {4,-2,-3,4,1};
    cout << s.subArrayRanges(nums) << endl;

    nums = {1,3,3};
    cout << s.subArrayRanges(nums) << endl;
}