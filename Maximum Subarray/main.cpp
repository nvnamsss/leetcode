#include <iostream>
#include <vector>
using namespace std;
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
class Solution {
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    
    int maxSubArray(vector<int>& nums, int low, int high)
    {
        int leftMax = INT16_MIN;
        int rightMax = INT16_MIN;
        int sum = 0;
        int mid = (low + high) / 2;

        if (high == low) return nums[low];

        for (int loop = mid; loop >= low; loop--)
        {
            sum += nums[loop];
            if (sum > leftMax) leftMax = sum;
        }

        sum = 0;
        for (int loop = mid + 1; loop <= high; loop++)
        {
            sum += nums[loop];
            if (sum > rightMax) rightMax = sum;
        }

        int descentdantMax = max(maxSubArray(nums, low, mid), maxSubArray(nums, mid + 1, high));
        return max(descentdantMax, leftMax + rightMax);
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
};
