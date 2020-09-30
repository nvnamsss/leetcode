/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

using System;
using System.Collections;
using System.Collections.Generic;

public class Solution {
    public string LargestNumber(int[] nums) {
        Array.Sort(nums, (a, b) => {
            int digita = (int)Math.Floor(Math.Log10(a) + 1);
            int digitb = (int)Math.Floor(Math.Log10(b) + 1);
            
            int na = (int)Math.Pow(10, digita - 1);
            int nb = (int)Math.Pow(10, digitb - 1);

            int fa = a / na;
            int fb = b / nb;
            while (na > 1 && nb > 1 && fa == fb)
            {
                a = a - na * (a / na);
                b = b - nb * (b / nb);
                na /= 10;
                nb /= 10;
                fa = a / na;
                fb = b / nb;
            }
            
            if (fa == fb) return digita.CompareTo(digitb);

            return fa.CompareTo(fb);
        });

        string result = string.Empty;
        for (int loop = 0; loop < nums.Length; loop++)
        {
            result += nums[loop];
        }

        return result;
    }
}