/*
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

 

Example 1:

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
Example 2:

Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
Example 3:

Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0
 

Constraints:

1 <= nums.length, k <= 105
-104 <= nums[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;

/*
    We using dp, says that dp[i] be that maximum score can reach at position i then we iterate over
    k step to find the maximum value can be reach at i thus the complexity is O(n*k)

    This complexity can be optimized to O(n) by providing a better way to get the maximum value in dp from range [i - k, i]
    thus this problem become finding maximum in a sliding window.

    Maximum in a sliding window could be easily solved by using deque
*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        deque<int> deque{0};

        dp[0] = nums[0];
        for (int loop = 1; loop < n; loop++)
        {
            dp[loop] = dp[deque.front()] + nums[loop];

            while (!deque.empty() && dp[deque.back()] <= dp[loop]) {
                deque.pop_back();
            }

            deque.push_back(loop);

            if (deque.front() <= loop - k) {
                deque.pop_front();
            }
        }

        return dp[n-1];        
    }
};