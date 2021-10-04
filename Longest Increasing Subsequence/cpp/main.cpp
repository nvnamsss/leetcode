/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> p(nums.size());
        vector<int> m(nums.size() + 1);
        int l = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int lo = 1;
            int hi = l;
            int newL = 0;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[m[mid]] < nums[i]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }   
            }

            newL = lo;
            p[i] = m[newL - 1];
            m[newL] = i;
            if (newL > l) {
                l = newL;
            }
        }
        
        return l;
    }
};