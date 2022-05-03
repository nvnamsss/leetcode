/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int get(vector<int> nums, int i) {
        if (i < 0 || i >= nums.size()) {
            return INT32_MIN;
        }
        return nums[i];
    }
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1) return 0;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int nl = get(nums, mid - 1);
            int nr = get(nums, mid + 1);
            if (nums[mid] > nl && nums[mid] > nr)
            {
                return mid;
            }
            else if (nums[mid] > nums[mid + 1])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2};
    cout << s.findPeakElement(nums) << endl;
    nums = {3, 2, 1};
    cout << s.findPeakElement(nums) << endl;
}