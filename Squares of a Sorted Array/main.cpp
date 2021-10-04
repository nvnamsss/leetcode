#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> rs = vector<int>(nums.size());
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                rs[index] = nums[right] * nums[right];
                right--;                
            } else {
                rs[index] = nums[left] * nums[left];
                left++;
            }

            index--;
        }
        return rs;
    }
};