/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int ans = 0;
        int sum = 0;
        map[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (map.find(sum - k) != map.end()) {
                ans += map[sum - k];
            }

            if (map.find(sum) == map.end()) {
                map.insert({sum, 0});
            }
            map[sum]++;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>{1,1,1};
    int rs = s.subarraySum(nums, 2);
    cout << rs << endl;

    nums = vector<int>{1,2,3,0};
    rs = s.subarraySum(nums, 3);
    cout << rs << endl;

    nums = vector<int>{-1,-1,1};
    rs = s.subarraySum(nums, 0);
    cout << rs << endl;

}