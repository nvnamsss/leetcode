/*
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

 

Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i])){
                continue;
            }
            s.insert(nums[i]);
        }

        vector<int> arr = vector<int>();
        int i = 0;
        for (auto &&it: s) {
            arr.push_back(it);
        }

        sort(arr.begin(), arr.end());
        int ans = nums.size();
        for (int i = 0; i < arr.size(); ++i) {
            int l = i;
            int r = arr.size() - 1;
            int target = arr[i] + nums.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (arr[m] > target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            int modify = nums.size() - (r - i);
            ans = min(ans, modify);
        }      

        return ans;
    }
};
int main() {
    Solution s;
    vector<int> arr = {41,33,29,33,35,26,47,24,18,28};
    s.minOperations(arr);
}