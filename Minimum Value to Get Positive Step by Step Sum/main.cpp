/*
Given an array of integers nums, you start with an initial positive value startValue.

In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that the step by step sum is never less than 1.

 

Example 1:

Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
                step by step sum
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2
Example 2:

Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive. 
Example 3:

Input: nums = [1,-2,-3]
Output: 5
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int> prefix = vector<int>(nums.size(), 0);
        int prefixMin = 0;
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (total + nums[i] < 1) {
                prefix[i] = 1 - nums[i] - total;
                total += prefix[i];
            }
            total += nums[i];
        }
        
        for (int i = 0; i < prefix.size(); i++)
        {
            prefixMin += prefix[i];
        }
        
        return max(prefixMin, 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {-3,2,-3,4,2};
    int rs = s.minStartValue(nums);
    cout << rs<< endl;
}