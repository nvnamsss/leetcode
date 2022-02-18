/*A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, a = 2, b = 3
Output: 2
Example 2:

Input: n = 4, a = 2, b = 3
Output: 6
Example 3:

Input: n = 5, a = 2, b = 4
Output: 10
Example 4:

Input: n = 3, a = 6, b = 4
Output: 8
 

Constraints:

1 <= n <= 109
2 <= a, b <= 4 * 104*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int nthMagicalNumber(int n, int a, int b) {
        long l = min(a, b);
        long r = min(a, b) * n;
        int A = a;
        int B = b;
        while (B > 0) {
            int temp = A;
            A = B;
            B = temp % B;
        }
        long lcm = a * b / A;

        while (l <= r) {
            long mid = l + (r - l) / 2;
            long count = mid / a + mid / b - mid / lcm;
            if (count < n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l % MOD;
    }
};