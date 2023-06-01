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
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        swap(nums[right], nums[pivotIndex]);
        int storeIndex = left;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] < pivotValue) {
                swap(nums[storeIndex], nums[i]);
                storeIndex++;
            }
        }
        swap(nums[storeIndex], nums[right]);

        return storeIndex;
    }

    void quickselect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return;
        int pivotIndex = left + (right - left) / 2;
        pivotIndex = partition(nums, left, right, pivotIndex);
        if (pivotIndex == k) {
            return;
        } else if (k < pivotIndex)   {
            quickselect(nums, left, pivotIndex - 1, k);
        } else {
            quickselect(nums, pivotIndex + 1, right, k);
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        quickselect(nums, 0, nums.size() - 1, k - 1);
        return nums[nums.size() - k];
        // priority_queue<int, vector<int>, less<int>> pq;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     pq.push(nums[i]);
        // }

        // int ans = 0;
        // while (k > 0)
        // {
        //     ans = pq.top();
        //     pq.pop();
        //     k--;
        // }
        // return ans;
    }
};

int main () {
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    cout << s.findKthLargest(nums, 2) << endl;
    
    cout << s.findKthLargest(nums, 5) << endl;
    cout << s.findKthLargest(nums, 1) << endl;

    nums = {2,1};
    cout << s.findKthLargest(nums, 2) << endl;
    nums = {7,6,5,4,3,2,1};
    cout << s.findKthLargest(nums, 2) << endl;
}