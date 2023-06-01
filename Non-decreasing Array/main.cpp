/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).



Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.


Constraints:

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return true;
        }
        int change = 1;
        if (nums[0] > nums[1])
        {
            nums[0] = nums[1];
            change--;
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i-1] && nums[i] >nums[i+1] && nums[i+1] >= nums[i-1]) {
                nums[i] = max(nums[i-1], nums[i+1]);
                change--;
            } else if (nums[i] < nums[i - 1])
            {
                nums[i] = nums[i-1];
                change--;
            }
        }

        if (nums[nums.size() - 1] < nums[nums.size() - 2])
        {
            nums[nums.size() - 1] = nums[nums.size() - 2];
            change--;
        }
        return change >= 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 4, 2, 3};
    cout << s.checkPossibility(nums) << endl;

    nums = {4, 2, 3};
    cout << s.checkPossibility(nums) << endl;
    nums = {-1, 4, 2, 3};
    cout << s.checkPossibility(nums) << endl;
    nums = {5,7,1,8};
    cout << s.checkPossibility(nums) << endl;

}