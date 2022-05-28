/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int searchLower(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return l;
    }

    int searchUpper(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] <= target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return r;
    }

    int search(vector<int> &nums, int target, int l, int r, bool extendToLower)
    {
        int mid = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                break;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        if (l > r)
        {
            return -1;
        }

        if (extendToLower)
        {
            int lower = search(nums, target, l, mid - 1, extendToLower);
            return lower == -1 ? mid : lower;
        }

        int upper = search(nums, target, mid + 1, r, extendToLower);
        return upper == -1 ? mid : upper;
    }

    vector<int> searchRange1(vector<int> &nums, int target)
    {
        int lower = search(nums, target, 0, nums.size() - 1, true);
        int upper = search(nums, target, 0, nums.size() - 1, false);

        return vector<int>{lower, upper};
    }

    vector<int> searchRange2(vector<int> &nums, int target)
    {
        int lower = searchLower(nums, target);
        int upper = searchUpper(nums, target);
        if (lower > upper) {
            lower = -1;
            upper = -1;
        }
        return vector<int>{lower, upper};
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return searchRange2(nums, target);
    }
};

void print(vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main() {
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> ans = s.searchRange(nums, 8);
    print(ans);
    ans = s.searchRange(nums, 6);
    print(ans);

    nums = {1};
    ans = s.searchRange(nums, 0);
    print(ans);
    nums = {};
    ans = s.searchRange(nums, 0);
    print(ans);

}