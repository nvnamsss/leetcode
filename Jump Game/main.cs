/* JUMP 1
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
*/

/* JUMP 2
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
*/

using System;
using System.Collections;
using System.Collections.Generic;
public class Solution {
    /*
    The problem could be partitioned to know if sum of index and value at index could
    greater than the length of array.
    We could try to find all possibilies by backtrack
    */
    bool rs;
    
    //Jump 2
    private bool Jump(int[] nums)
    {
        int required = 1;
        int step = nums.Length;
        Stack<int> s= new Stack<int>();
        for (int loop = nums.Length - 2; loop >= 0; loop--)
        {
            if (nums[loop] >= required)
            {
                step = step - (nums[loop] - required);
                required = 1;

                int n = nums[loop];
                while (s.Count > 0 && s.Peek() <= n)
                {
                    n -= s.Pop();
                }

                s.Push(nums[loop]);
            }
            else{
                required += 1;
            }
        }

        return s.Count;
    }

    //Jump 1
    public bool CanJump(int[] nums) {
        rs =false;
        int required = 1;
        for (int loop = nums.Length - 2; loop >= 0; loop--)
        {
            if (nums[loop] >= required)
            {
                required = 1;
            }
            else{
                required += 1;
            }
        }

        if (required == 1)
        {
            rs = true;
        }
        return rs;
    }
}