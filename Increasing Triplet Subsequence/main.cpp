#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        int i = nums.size() - 1;
        int down = nums[i];
        int peak = nums[i];
        i--;
        while (i >= 0) {
            if (nums[i] < down && nums[i] < peak) return true;

            if (nums[i] > peak) {
                peak = nums[i];
            } else {
                down = nums[i];
            }

            i--;
        }
        
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>{5,4,3,0,1,2};
    bool rs = s.increasingTriplet(nums);
    cout << rs << endl;
    nums = vector<int>{2,4,-2,-3};
    rs = s.increasingTriplet(nums);
    cout << rs << endl;

    nums = vector<int>{1,2,3,10,9,8,7,6,5,4};
    rs = s.increasingTriplet(nums);
    cout << rs << endl;

    nums = vector<int>{0,4,2,1,0,-1,-3};
    rs = s.increasingTriplet(nums);
    cout << rs << endl;
}