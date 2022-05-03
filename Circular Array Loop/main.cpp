/*
You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

If nums[i] is positive, move nums[i] steps forward, and
If nums[i] is negative, move nums[i] steps backward.
Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

A cycle in the array consists of a sequence of indices seq of length k where:

Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
Every nums[seq[j]] is either all positive or all negative.
k > 1
Return true if there is a cycle in nums, or false otherwise.

 

Example 1:

Input: nums = [2,-1,1,2,2]
Output: true
Explanation:
There is a cycle from index 0 -> 2 -> 3 -> 0 -> ...
The cycle's length is 3.
Example 2:

Input: nums = [-1,2]
Output: false
Explanation:
The sequence from index 1 -> 1 -> 1 -> ... is not a cycle because the sequence's length is 1.
By definition the sequence's length must be strictly greater than 1 to be a cycle.
Example 3:

Input: nums = [-2,1,-1,-2,-2]
Output: false
Explanation:
The sequence from index 1 -> 2 -> 1 -> ... is not a cycle because nums[1] is positive, but nums[2] is negative.
Every nums[seq[j]] must be either all positive or all negative.
 

Constraints:

1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
nums[i] != 0
 

Follow up: Could you solve it in O(n) time complexity and O(1) extra space complexity?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int jump(vector<int> &nums, int i)
    {
        i = (i + nums[i]) % nums.size();
        if (i < 0)
            i += nums.size();
        return i;
    }

public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int turtoise = 0;
        int hare = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                continue;
            int count = 1;
            int sign = nums[i];

            turtoise = i;
            hare = jump(nums, jump(nums, i));

            while (turtoise != hare && sign * nums[turtoise] > 0 && sign * nums[hare] > 0)
            {
                turtoise = jump(nums, turtoise);
                hare = jump(nums, jump(nums, hare));
                count++;
            }

            if (turtoise == hare && count > 1)
                return true;

            turtoise = i;
            hare = jump(nums, turtoise);
            while (nums[turtoise] != 0) {
                nums[turtoise] = 0;
                turtoise = hare;
                hare = jump(nums, turtoise);
            }
        }

        return false;
    }
};