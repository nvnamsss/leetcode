/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.



Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void occupy(vector<int> &nums, int pos)
    {
        if (pos == 0 || pos >= nums.size())
        {
            return;
        }

        int nextPos = nums[pos];
        nums[pos] = 0;
        if (nextPos > 0 && nextPos < nums.size()) {
            occupy(nums, nextPos);
            nums[nextPos] = nextPos;
        }
    }

public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0) {
                occupy(nums, i);
            }
        }

        int ans = 1;
        while (ans < nums.size() && nums[ans] > 0)
        {
            ans++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 0};
    cout << s.firstMissingPositive(nums) << endl;
    nums = {3, 4, -1, 1};
    cout << s.firstMissingPositive(nums) << endl;
    nums = {7, 8, 9, 11, 12};
    cout << s.firstMissingPositive(nums) << endl;
    nums = {1, 2, 7, 5,4, 11, 12};
    cout << s.firstMissingPositive(nums) << endl;
}