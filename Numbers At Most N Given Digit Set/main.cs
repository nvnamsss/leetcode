/*
Given an array of digits, you can write numbers using each digits[i] as many times as we want.  For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

 

Example 1:

Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
Example 2:

Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.
Example 3:

Input: digits = ["7"], n = 8
Output: 1
 

Constraints:

1 <= digits.length <= 9
digits[i].length == 1
digits[i] is a digit from '1' to '9'.
All the values in digits are unique.
1 <= n <= 109
*/

using System;
using System.Collections.Generic;
public class Solution {
    public int recursive(string[] digits, int n) 
    {
        int total = 0;
        int digit = (int)Math.Floor(Math.Log10(n) + 1);

        for (int loop = 0; loop < digits.Length; loop++)
        {
            if (digit == 1) {
                if ((digits[loop][0] - '0') <= n) total++;
            } else {
                int ten = (int)Math.Pow(10, digit - 1);
                int num = (digits[loop][0] - '0');
                if (num > n / ten) continue;
                if (num == n / ten) {
                    int nn = n - ten * (n / ten);
                    if (digit - Math.Floor(Math.Log10(nn) + 1)> 1) continue;
                    total += recursive(digits, nn);
                } else {
                    total += (int)Math.Pow(digits.Length, digit - 1);
                }

            }
        }

        return total;
    }

    public int AtMostNGivenDigitSet(string[] digits, int n) {
        int total = 0;
        int digit = (int)Math.Floor(Math.Log10(n) + 1);

        for (int loop = 1; loop < digit; loop++)
        {
            total += (int)Math.Pow(digits.Length, loop);
        }

        total += recursive(digits, n);
        //firstly, we count amount of number which obviously less than n that digit are less than n's digit
        //for the rest, we just need to find amount of number that digit are equal to n's digit by recursive
        return total;
    }
}