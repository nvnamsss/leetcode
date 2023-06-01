/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;
// series - sum = c - b
// series ^ sum = c + b
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int series = 0;
        int sum = 0;
        int xo = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            series += i + 1;
        }
        
        int cmb = series - sum;
        int cpb = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cpb ^= nums[i];
            cpb ^= (i + 1);
        }
        
        int c = (cmb + cpb) / 2;
        int b = cpb - c;
        // int b = (sum - xo) / 2;
        // int c = series - (sum - b);

        return {b, c};
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,3,5};
    s.findErrorNums(nums);

    nums = {1,2,2,4};
    s.findErrorNums(nums);
}