#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findPivot(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] <= nums[r]) {
            return 0;
        }
        while (l <= r) {
            int p =l +  (r - l) / 2;
            if (nums[p] > nums[p+1]) {
                return p+1;
            } else {
                if (nums[p] > nums[l]) {
                    l = p + 1;
                } else {
                    r = p - 1;
                }
            }
        }

        return 0;
    }
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }
    int twopass(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        if (nums[pivot] == target) {
            return pivot;
        }

        if (nums[pivot] > target) {
            return binarySearch(nums, 0, pivot - 1, target);
        }

        return binarySearch(nums, pivot + 1, nums.size() - 1, target);
    }

    int onepass(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l ) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return twopass(nums, target);
    }
};

int main() {
    vector<int> nums = vector<int>{4,5,6,7,0,1,2};
    Solution s;
    cout << s.search(nums, 0) << endl;

    nums = vector<int>{5,1,3};
    cout << s.search(nums, 3) << endl;

    nums = vector<int>{1};
    cout << s.search(nums, 0) << endl;

    nums = vector<int>{3, 1};
    cout << s.search(nums, 3) << endl;

}