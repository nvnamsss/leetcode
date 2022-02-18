/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // set<int> set;
        // unordered_map<int, vector<int>> m;
        vector<int> lis = vector<int>(nums.size(), 1);
        vector<int> idx = vector<int>(nums.size(), -1);
        sort(nums.begin(), nums.end());
        /*
        1 6 12 18 36
        */
        int ans = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (lis[j] + 1 > lis[i] && nums[i] % nums[j] == 0) {
                    lis[i] = lis[j] + 1;
                    idx[i] = j;
                }

                if (lis[i] > ans) {
                    ans = lis[i];
                    index = i;
                }
            }
        }
        vector<int> rs;
        while (index != -1) {
            rs.push_back(nums[index]);
            index = idx[index];
        }
        return rs;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    s.largestDivisibleSubset(nums);
}