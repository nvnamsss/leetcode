#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void reverse(vector<int> &nums, int l, int r)
    {
        while (l < r)
        {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            l++;
            r--;
        }
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i+1] <= nums[i])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i])
            {
                j--;
            }
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }

        reverse(nums, i + 1, nums.size() - 1);
    }
};