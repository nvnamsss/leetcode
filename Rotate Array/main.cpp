#include <bits/stdc++.h>
using namespace std;

class Solution {
    void r(vector<int>& nums, int from, int to, int k) {
        int n = to - from;
        if (n <= 1) return;
        k = k % n;
        for (int i = 0; i < k; i++)
        {
            int symetric = to - k + i;
            int temp = nums[symetric];
            nums[symetric] = nums[from + i];
            nums[from + i]=  temp;
        }
        if (k > 0) {
            r(nums, from + k, to, k);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        r(nums,0, nums.size(), k);
    }
};

int main() {
    vector<int> nums =vector<int>{-1,-100,3,99};
    Solution s;
    s.rotate(nums, 2);

    nums = vector<int>{1,2,3,4,5,6,7};
    s.rotate(nums, 3);
}