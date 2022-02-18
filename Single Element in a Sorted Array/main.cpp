/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1) return nums[0];

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 != 0 && nums[mid] == nums[mid - 1]))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return nums[l];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int rs = s.singleNonDuplicate(nums);
    cout << rs << endl;
    nums = {3, 3, 7, 7, 10, 11, 11};
    rs = s.singleNonDuplicate(nums);
    cout << rs << endl;
    nums = {1};
    rs = s.singleNonDuplicate(nums);
    cout << rs << endl;
    nums = {1,1,3};
    rs = s.singleNonDuplicate(nums);
    cout << rs << endl;
}