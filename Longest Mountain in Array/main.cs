/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
 

Follow up:

Can you solve it using only one pass?
Can you solve it in O(1) space?
*/

using System;
public class Solution
{

    public int LongestMountain(int[] arr)
    {
        int rs = 0;
        int state = 0;
        int length = 1;

        for (int loop = 0; loop < arr.Length - 1; loop++)
        {
            if (arr[loop + 1] == arr[loop]) {
                if (state == 2) rs = Math.Max(rs, length);
                state = 0;
                length = 1;
                continue;
            }    
            bool s = arr[loop + 1] > arr[loop];
            switch (state) {
                case 0:
                    if (s) {
                        state = 1;
                        length += 1;
                    }
                break;
                case 1:
                    length++;
                    if (!s) {
                        state = 2;
                    }
                break;
                case 2:
                    if (s) {
                        rs = Math.Max(rs, length);
                        state = 1;
                        length = 2;
                    } else {
                        length++;
                    }
                break;
            }
        }

        if (state == 2) rs = Math.Max(rs, length);
        return rs;
        // bool incr = true;
        // int length = 0;
        // for (int loop = 0; loop < arr.Length - 1; loop++)
        // {
        //     if (arr[loop + 1] == arr[loop])
        //     {
        //         incr = true;
        //         length = 0;
        //         continue;
        //     }

        //     bool s = arr[loop + 1] > arr[loop];
        //     if (!incr && s)
        //     {
        //         incr = true;
        //         length = 0;
        //     }

        //     if (incr == s || incr && !s)
        //     {
        //         length++;
        //         incr = s;
        //     }

        //     if (length > 2 && !incr)
        //     {
        //         rs = Math.Max(rs, length + 1);
        //     }
        // }

        // if (length > 2 && !incr)
        // {
        //     rs = Math.Max(rs, length + 1);
        // }
        // return rs;
    }
}