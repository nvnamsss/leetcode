/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.



Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> result;
    bool shouldSwap(vector<int> &nums, int start, int current)
    {
        for (int i = start; i < current; i++)
        {
            if (nums[i] == nums[current])
            {
                return false;
            }
        }
        return true;
    }

    void recursive(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (i == index || nums[i] != nums[index])
            {
                if (shouldSwap(nums, index, i))
                {
                    swap(nums[i], nums[index]);
                    recursive(nums, index + 1);
                    swap(nums[i], nums[index]);
                }
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        recursive(nums, 0);
        return result;
    }
};