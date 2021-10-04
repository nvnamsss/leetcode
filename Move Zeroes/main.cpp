/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes2(vector<int>& nums) {
        int p1 = 0;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) {
                nums[p1] = nums[i];
                p1++;
            }
        }

        for (int i = p1; i < n; i++)
        {
            nums[i] = 0;
        }
        
    }

    void moveZeroes(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) count++;
        }

        while (count > 0) {
            if (nums[p1] == 0) {
                if (p2 < p1) {
                    p2 = p1 + 1;
                }

                while (nums[p2] == 0) {
                    p2++;
                }

                int t = nums[p1];
                nums[p1] = nums[p2];
                nums[p2] = t;
            }
            p1++;
            count--;
        }
        
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>{0,1,0,3,12};
    s.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    nums = vector<int>{0,1,0,0,0,3,0,0,12};
    s.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}