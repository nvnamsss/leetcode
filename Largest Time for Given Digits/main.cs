/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9
*/

using System;
using System.Collections;
public class Solution {
    public int maxtime = -1;

    private void Swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void permutate(int[] A, int start)
    {
        if (start == A.Length)
        {
            build(A);
            return;
        }

        for (int loop = 0; loop < A.Length; loop++)
        {
            Swap(A, start, loop);
            permutate(A, start + 1);
            Swap(A, start, loop);
        }
    }

    void build(int[] A)
    {
        int h = A[0] * 10 + A[1];
        int m =  A[2] * 10 + A[3];

        if ((h >= 0 && h < 24) && (m >= 0 && m < 60))
        {
            this.maxtime = Math.Max(this.maxtime, h * 60 + m);
        }
    }

    public string LargestTimeFromDigits(int[] A) {
        if (A.Length == 0) return "00:00";
        //do here
        permutate(A, 0);
        
        //result
        string time = "";
        if (maxtime == -1) return time;
        int h = maxtime / 60;
        int m = maxtime % 60;
        if (h < 10)
        {
            time += "0" + h;
        }
        else {
            time += h;
        }

        time += ":";
        if (m < 10)
        {
            time += "0" + m;
        }else{
            time += m;
        }

        return time;
    }
}