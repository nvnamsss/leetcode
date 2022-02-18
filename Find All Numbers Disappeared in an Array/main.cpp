/*

5119

337

Add to List

Share
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
    void swap(vector<int>& nums, int a, int b) {
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> arr = vector<int>(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        vector<int> rs;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1) {
                rs.push_back(i + 1);
            }
        }
        
        return rs;
    }
};

int main() {
    Solution s;
    vector<int> arr = {4,3,2,7,8,2,3,1};
    s.findDisappearedNumbers(arr);
}