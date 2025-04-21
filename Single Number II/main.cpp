/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99


Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int abstractSingleNumber(vector<int>& nums, int k) {
        vector<int> seen = vector<int>(k - 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < seen.size(); j++)
            {
                seen[j] = (seen[j] ^ nums[i]);
                for (int m = 0; m < seen.size(); m++)
                {
                    if (m == j) {
                        continue;
                    }

                    seen[j] &= ~seen[m];
                }
            }
            
        }
        
        return seen[0];
    }
public:
    int singleNumber(vector<int> &nums)
    {
        return abstractSingleNumber(nums, 3);
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,0,1,0,1,99};
    cout << s.singleNumber(nums) << endl;

}