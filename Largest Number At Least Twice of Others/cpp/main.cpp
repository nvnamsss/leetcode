/*
You are given an integer array nums where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

 

Example 1:

Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.
Example 2:

Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.
Example 3:

Input: nums = [1]
Output: 0
Explanation: 1 is trivially at least twice the value as any other number because there are no other numbers.
 

Constraints:

1 <= nums.length <= 50
0 <= nums[i] <= 100
The largest element in nums is unique.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {  
        int max = 0;
        int index = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max) {
                max = nums[i];   
                index = i;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (2 * nums[i] > max && nums[i] != max) return -1;
        }
        
        return index;
    }
};