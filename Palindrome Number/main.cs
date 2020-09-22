/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/
using System;

public class Solution {
    public bool IsPalindrome(int x) {
int digit = (int)Math.Floor(Math.Log10(x) + 1);
            int sign = Math.Sign(x);
            if (sign < 0) return false;

            int[] array = new int[digit];
            for (int loop = 0; loop < digit; loop++)
            {
                int d = (int)Math.Pow(10, digit - loop - 1);
                array[loop] = x / d;
                x = x - (x / d) * d;
            }

            for (int loop = 0; loop < array.Length; loop++)
            {
                if (array[loop] != array[array.Length - loop - 1]) return false;
            }

            return true;
    }
}