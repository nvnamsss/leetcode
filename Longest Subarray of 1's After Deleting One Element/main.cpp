/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.



Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans = 0;
        vector<int> prefix = vector<int>(nums.size() + 1);
        vector<int> suffix = vector<int>(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                prefix[i + 1] = prefix[i] + 1;
                ans = max(ans, prefix[i+1]);
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i])
            {
                suffix[i] = suffix[i + 1] + 1;
            }
        }
        
        ans = ans - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!nums[i]) {
                ans = max(ans, prefix[i] + suffix[i + 1]);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1};
    s.longestSubarray(nums);
}