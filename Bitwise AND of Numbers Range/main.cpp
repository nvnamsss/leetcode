/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0 || left == right) return 0;
        int rs = 0;
        int n = floor(log2(left)) + 1;
        uint mask = (1 << n);
        mask -= 1;
        cout << "n: " << n << endl;
        for (int i = 0; i < n; i++)
        {
            uint bitoff = mask & ~(1 << i);
            cout << "bitoff: " << bitoff << endl;

            if (bitoff < left) {
                rs = rs | (1 << i);
            }
        }
        
        return rs;
    }
};

int main() {
    Solution s;
    s.rangeBitwiseAnd(1, 2);
}