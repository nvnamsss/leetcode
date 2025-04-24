/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<vector<int>> candidates = vector<vector<int>>(2, vector<int>(2));
        int threshold = nums.size() / 3;
        for (int i = 0; i < nums.size(); ++i)
        {
            bool match = false;
            for (int j = 0; j < candidates.size(); ++j)
            {
                if (candidates[j][0] == nums[i])
                {
                    candidates[j][1]++;
                    match = true;
                    break;
                }
            }

            if (match)
            {
                continue;
            }

            for (int j = 0; j < candidates.size(); ++j)
            {
                if (candidates[j][1] == 0)
                {
                    candidates[j][0] = nums[i];
                    candidates[j][1]++;
                    match = true;
                    break;
                }
            }

            if (match)
            {
                continue;
            }

            for (int j = 0; j < candidates.size(); j++)
            {
                candidates[j][1]--;
            }
        }

        for (int i = 0; i < candidates.size(); i++)
        {
            candidates[i][1] = 0;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < candidates.size(); j++)
            {
                if (nums[i] == candidates[j][0])
                {
                    candidates[j][1]++;
                    break;
                }
            }
        }

        vector<int> ans = vector<int>();
        for (int i = 0; i < candidates.size(); ++i)
        {
            if (candidates[i][1] > threshold)
            {
                ans.push_back(candidates[i][0]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 1, 1, 3, 1, 4, 5, 6};
    s.majorityElement(nums);
}