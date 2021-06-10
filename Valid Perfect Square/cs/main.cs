/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1
*/

using System;
public class Solution {
    public bool IsPerfectSquare(int num) {
        long low = 0;
        long high = num;
        while (low <= high) {
            long mid = (low + high) / 2;
            long p = mid * mid;
            if (p == num) return true;
            else if (p > num) high = mid - 1;
            else if (p < num) low = mid + 1;            
        }

        return false;
    }

    private bool IsPerfectSquare2(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }

// 1 = 1
// 4 = 1 + 3
// 9 = 1 + 3 + 5
// 16 = 1 + 3 + 5 + 7
// 25 = 1 + 3 + 5 + 7 + 9
// 36 = 1 + 3 + 5 + 7 + 9 + 11
// ....
// so 1+3+...+(2n-1) = (2n-1 + 1)n/2 = nn
}