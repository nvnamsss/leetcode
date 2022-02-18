/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int red = 0;
        int blue = nums.size() - 1;
        int i = 1;
        while (red <= i && i <= blue)
        {
            if (nums[i] == 0 && red < i)
            {
                int t = nums[red];
                nums[red] = nums[i];
                nums[i] = t;
                red++;
            }
            else if (nums[i] == 2 && i < blue)
            {
                int t = nums[blue];
                nums[blue] = nums[i];
                nums[i] = t;
                blue--;
            }
            else
            {
                i++;
            }
        }
    }
};

int main()
{
    vector<int> nums = vector<int>{2, 0, 1};
    Solution s;
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    nums = vector<int>{2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}