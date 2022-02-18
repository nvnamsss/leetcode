#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 2;
        int fast = 2;
        while (fast < nums.size()) {
            if (nums[slow-2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++; 
        }

        return nums.size() < 2 ? nums.size() : slow;
    }
};