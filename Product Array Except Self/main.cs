using System;
// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

//Solution:
/* Go a head and Go backward.
When go ahead, the ouput storage the product of the previous number product
Then when go backward, the output will multiply with the next number product
After 2 iterates, all out put are producted

Example:
[2 4 5 7]
Go A head we got the output:
[1 2 8 20]
The array is sorted thus the first number always receive 1. then we keep iterating, then multiply the output[i] 
with the previous number: at [1] 2 equal to ...*nums[1] = 2, at [2] 8 equal to ...*nums[2] = 2 * 4

Go backward we got the output:
[140 70 56 20]
The last number is already done thus we skip it. At [2] 56 equal to output[2] * nums[2]... = 8 * 7,
at [1] 70 equal to output[1] * nums[1]... = 2 * 5 * 7
at [0] 140 eqaul to output[0] * nums[0]... = 1 * 4 * 5 * 7

Here we using dynamic programming to avoid the duplication of ...nums[i] and nums[i].... 
*/
public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        if (nums.Length == 0) return new int[0];
        int[] output = new int[nums.Length];

        int t = nums[0];
        output[0] = 1; 
        for (int loop = 1; loop < nums.Length; loop++)
        {
            output[loop] = t;
            t *= nums[loop];
        }

        t = nums[nums.Length - 1];
        for (int loop = nums.Length - 2; loop >= 0; loop--)
        {
            output[loop] *= t;
            t *= nums[loop];
        }

        return output;
    }
}