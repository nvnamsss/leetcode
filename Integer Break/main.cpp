/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:

2 <= n <= 58
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n < 3) return 1;
        if (n == 3) return 2;

        int num = n / 3;
        int r = n % 3;
        if (r == 1) {
            num--;
            r = 4;
        } else if (r == 0) {
            r = 1;
        }

        return pow(3, num) * r;
    }
};