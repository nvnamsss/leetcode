/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

//implement dequeue in .net

using System;
using System.Collections.Generic;

public class Solution
{
    public int[] MaxSlidingWindow(int[] nums, int k)
    {
        List<int> rs = new List<int>();
        int[] arr = new int[] { int.MinValue, -1 };
        bool reset = true;
        for (int loop = 0; loop < nums.Length; loop++)
        {
            if (reset)
            {
                for (int loop2 = 0; loop2 < k; loop2++)
                {
                    if (nums[loop2] > arr[0])
                    {
                        arr[0] = nums[loop2];
                        arr[1] = loop2;
                    }
                }
            }
            else
            {
                if (nums[loop + k] > arr[0])
                {
                    arr[0] = nums[loop + k];
                    arr[1] = loop + k;
                }
            }
            rs.Add(arr[0]);
            reset = loop + 1 > loop + k;
        }
        return rs.ToArray();
    }
}