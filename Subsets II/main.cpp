/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> rs = vector<vector<int>>{{}};
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) == map.end())
            {
                map.insert({nums[i], 0});
            }

            map[nums[i]]++;
        }
        for (auto &&v : map)
        {
            vector<vector<int>> newv;
            for (int i = 0; i < rs.size(); i++)
            {
                for (int j = 0; j < v.second; j++)
                {
                    vector<int> clone = rs[i];
                    vector<int> append = vector<int>(j + 1, v.first);
                    clone.insert(clone.end(), append.begin(), append.end());
                    newv.push_back(clone);
                }
            }

            rs.insert(rs.end(), newv.begin(), newv.end());
        }

        return rs;
    }
};

int main()
{
    Solution s;
    vector<int> nums = vector<int>{1, 2, 2};
    vector<vector<int>> rs = s.subsetsWithDup(nums);
}