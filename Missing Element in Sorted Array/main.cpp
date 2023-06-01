/*
Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, return the kth missing number starting from the leftmost number of the array.

 

Example 1:

Input: nums = [4,7,9,10], k = 1
Output: 5
Explanation: The first missing number is 5.
Example 2:

Input: nums = [4,7,9,10], k = 3
Output: 8
Explanation: The missing numbers are [5,6,8,...], hence the third missing number is 8.
Example 3:

Input: nums = [1,2,4], k = 3
Output: 6
Explanation: The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 107
nums is sorted in ascending order, and all the elements are unique.
1 <= k <= 108
 

Follow up: Can you find a logarithmic time complexity (i.e., O(log(n))) solution?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else { 
                r = m - 1;
            }
        }
        return r;
    }

    int binarySearch(vector<int>& nums, int k) {
        int ans = nums[0];
        int from = 0;
        int i = 0;
        while (i < nums.size() - 1 && nums[i] + k >= nums[i + 1]) {
            i = search(nums, nums[i] + k);
            int missed = nums[i] - nums[from] - (i - from);
            k -= missed;
            from = i;
        }

        return nums[i] + k;
    }

    int binarySearch2(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        int m = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            int missed = nums[m] - nums[0] - m;
            if (missed < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int missed = nums[r] - nums[0] - (r);
        return nums[r] + k - missed;
    }

    int linear(vector<int>& nums, int k) {
        int ans = nums[0];
        int i = 1;
        for (i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] + k >= nums[i]) {
                k -= (nums[i] - nums[i - 1] - 1);
            } else {
                break;
            }
        }

        return nums[i - 1] + k;
    }
public:
    int missingElement(vector<int>& nums, int k) {
        return binarySearch2(nums, k);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,4};
    cout << s.missingElement(nums, 100) << endl;

    nums = {4,7,9,10};
    cout << s.missingElement(nums, 3) << endl;
    nums = {1,2,3,4};
    cout << s.missingElement(nums, 3) << endl;
    nums = {4,7,9,1000000};
    cout << s.missingElement(nums, 70000) << endl;
    
}