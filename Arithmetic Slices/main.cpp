/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
Example 2:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return 0;
        }
        vector<int> val = vector<int>(nums.size(), 0);
        int ans = 0;

        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                val[i] = val[i - 1] + 1;
                ans += val[i];
            }
        }


        return ans;
    }
};