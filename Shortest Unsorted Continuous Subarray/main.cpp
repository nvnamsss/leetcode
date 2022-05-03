/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.



Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0


Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105


Follow up: Can you solve it in O(n) time complexity?

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        // nums.insert(nums.begin(), INT32_MIN);
        // nums.push_back(INT32_MAX);
        int l = 0;
        int r = nums.size() - 1;

        while (l < r && nums[l] <= nums[l + 1])
        {
            l++;
        }

        while (r > l && nums[r] >= nums[r - 1])
        {
            r--;
        }

        if (l == r)
        {
            return 0;
        }

        int minV = nums[r];
        int maxV = nums[l];
        for (int i = l; i <= r; i++)
        {
            minV = min(minV, nums[i]);
            maxV = max(maxV, nums[i]);
        }

        while (l >= 0 && nums[l] > minV)
        {
            l--;
        }

        while (r < nums.size() && nums[r] < maxV)
        {
            r++;
        }

        return r - l - 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << s.findUnsortedSubarray(nums) << endl;
    nums = {1, 2, 3, 4};
    cout << s.findUnsortedSubarray(nums) << endl;
    nums = {1};
    cout << s.findUnsortedSubarray(nums) << endl;
    nums = {2, 3, 6, 4, 8, 10, 9, 15};
    cout << s.findUnsortedSubarray(nums) << endl;
    nums = {2, 1};
    cout << s.findUnsortedSubarray(nums) << endl;
    nums = {1, 2, 3, 3, 3};
    cout << s.findUnsortedSubarray(nums) << endl;
    nums = {1, 3, 2, 2, 2};
    cout << s.findUnsortedSubarray(nums) << endl;
    nums = {7,6,5,4,3};
    cout << s.findUnsortedSubarray(nums) << endl;
}