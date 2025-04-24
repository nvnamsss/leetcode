/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> prefix = vector<int>(nums.size() + 1);
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i+1] = prefix[i] + nums[i];
        }      

        int sum = 0;

        m.insert({0, 0});
        for (int i = nums.size() - 1; i >= 0; --i) {
            sum += nums[i];
            if (m.find(sum) == m.end()) {
                m.insert({sum, nums.size() -  i});
            }
        }

        int ans = nums.size() + 1;
        for (int i = 0; i <= nums.size(); ++i) {
            int left = prefix[i];
            int right = x - left;
            if (m.find(right) != m.end()) {
                int ops = i + m[right];
                ans = min(ans, ops);
            }
        }

        return ans < nums.size() + 1 ? ans : -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,4,2,3};
    cout << s.minOperations(nums, 5) << endl;
    nums = {5,6,7,8,9};
    cout << s.minOperations(nums, 4) << endl;
    nums = {3,2,20,1,1,3};
    cout << s.minOperations(nums, 10) << endl;
}