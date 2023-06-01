/*
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sum = vector<int>(nums.size() + 1);
        unordered_map<int, int> m;
        m.insert({0, 0});
        for (int i = 0; i < nums.size(); i++)
        {
            sum[i + 1] = sum[i] + nums[i];
            int remainder = sum[i+1] % k;
            m.insert({remainder, i + 1});
            if (m.find(remainder) != m.end()) {
                if (m[remainder] < i) {
                    return true;
                }
            }
        }
                
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {23,2,6,4,7};
    s.checkSubarraySum(nums, 13);
}