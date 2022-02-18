/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        int ans = 0;
        while (k > 0)
        {
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};

int main () {
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    int rs = s.findKthLargest(nums, 2);
    cout << rs << endl;
}