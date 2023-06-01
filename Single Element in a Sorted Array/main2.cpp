#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums[0] != nums[1]) {
            return nums[0];
        }

        if (nums[r] != nums[r - 1]) {
            return nums[r];
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            // if (nums[m] != nums[m-1] && nums[m] != nums[m+1]) {
            //     return nums[m];
            // }
            bool even = m%2 == 0;
            if ((even && nums[m] == nums[m+1]) || (!even && nums[m] != nums[m+1])) {
                // find right
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return nums[l];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,2,3,3,4,4};
    cout << s.singleNonDuplicate(nums) << endl;

    nums = {1,1,2,3,3,4,4};
    cout << s.singleNonDuplicate(nums) << endl;

    nums = {1,1,2,3,3,4,4,8,8};
    cout << s.singleNonDuplicate(nums) << endl;

    nums = {1,1,2,2,3,3,4,4,8,12,12};
    cout << s.singleNonDuplicate(nums) << endl;
}