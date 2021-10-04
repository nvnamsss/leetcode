/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[nums1.size() + 1][nums2.size() + 1];
        int rs = 0;
        
        for (int i = 0; i <= nums1.size() ; i++)
        {
            for (int j = 0; j <= nums2.size(); j++)
            {
                dp[i][j] = 0;
            }
        }
        
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            for (int j = nums2.size() - 1; j >= 0; j--)
            {
                dp[i][j] = 0;
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    rs = max(dp[i][j], rs);
                }
            }
        }

        return rs;
    }
};