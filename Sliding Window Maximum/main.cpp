/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int size = nums.size();
        int loop = 0;
        for (loop = 0; loop < k; loop++)
        {
            while (!q.empty() && nums[loop] >= nums[q.back()])
                q.pop_back();

            q.push_back(loop);
        }
        

        for (; loop < size; loop++)
        {
            ans.push_back(nums[q.front()]) ;
			// check if max element is out of range pop it 
             while(!q.empty() && q.front()<=loop-k)
                q.pop_front() ;
            
			
            while(!q.empty() && nums[loop]>=nums[q.back()])
                q.pop_back() ;
            
            q.push_back(loop) ;
            ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }
};