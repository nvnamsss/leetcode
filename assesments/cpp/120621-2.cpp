/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*
            Due to array is sorted, even if its rotated, we still have two sorted subarray
            thus for finding a target is in array, we can apply binary search on subarray which has O(log(n)) time complexity

            then the problem become: finding the pivot, search time complexity be O(log(n)) 
            thus finding pivot time must also be O(log(n)) or lower.

            we known that if a subarray contains the pivot then subarray[start] > subarray[end]
            same as finding on a tree, we divide the array to two equal subarrays, then the subarray that not satisfying 
            the above condition will be ignored, we keep do the same thing with the pivot containing subarray till we find the pivot.

            finding pivot cost O(log(n)) time complexity thus the overall time complexity be O(log(n))
        */
       if (nums.size() == 0) return false;

       int lo = 0;
       int hi = nums.size() - 1;

        while (lo <= hi) {
            while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
            while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
            
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return true;

            if (nums[mid] >= nums[lo]) {
                // F
                if (target >= nums[lo] && target <= nums[mid]) {
                    // target also in F and target between lo and mid
                    hi = mid - 1;
                } else {
                    // otherwise target in S
                    lo = mid + 1;
                }
            } else {
                // S
                if (target >= nums[mid] && target <= nums[hi]) {
                    // target also in S and target between mid and hi
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }

            }
        }
        return false;
    }

};

int main() {
    Solution s;
    vector<int> nums{2,5,6,0,0,1,2};
    bool rs = s.search(nums, 0);

    cout << "Result: " << rs << " - Expect: " << true;
    return 0;
}