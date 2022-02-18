/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int ans1 = 0;
        int ans2 = 0;
        unordered_map<int, int> m;
        int count = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
            while (m.size() >= k)
            {
                if (--m[nums[l]] == 0)
                {
                    m.erase(nums[l]);
                }
                l++;
            }
            ans1 += i - l + 1;
        }
        l = 0;
        m.clear();
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
            while (m.size() > k)
            {
                if (--m[nums[l]] == 0)
                {
                    m.erase(nums[l]);
                }
                l++;
            }
            ans2 += i - l + 1;
        }

        return ans2 - ans1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 1, 2, 3};
    cout << s.subarraysWithKDistinct(nums, 2) << endl;
}
