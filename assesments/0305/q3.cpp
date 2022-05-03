/*
A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

We can rotate digits of a number by 180 degrees to form new digits.

When 0, 1, 6, 8, and 9 are rotated 180 degrees, they become 0, 1, 9, 8, and 6 respectively.
When 2, 3, 4, 5, and 7 are rotated 180 degrees, they become invalid.
Note that after rotating a number, we can ignore leading zeros.

For example, after rotating 8000, we have 0008 which is considered as just 8.
Given an integer n, return true if it is a confusing number, or false otherwise.

 

Example 1:


Input: n = 6
Output: true
Explanation: We get 9 after rotating 6, 9 is a valid number, and 9 != 6.
Example 2:


Input: n = 89
Output: true
Explanation: We get 68 after rotating 89, 86 is a valid number and 86 != 89.
Example 3:


Input: n = 11
Output: false
Explanation: We get 11 after rotating 11, 11 is a valid number but the value remains the same, thus 11 is not a confusing number
 

Constraints:

0 <= n <= 109
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> m = {
        {0, 0}, {1,1}, {6, 9}, {9, 6}, {8, 8}
    };
public:
    bool confusingNumber(int n) {
        int rotated = 0;
        int v = n;
        while (v > 0) {
            int d = v % 10;
            if (m.find(d) == m.end()) {
                return false;
            }

            rotated = rotated * 10 + m[d];
            v = v / 10;
        }

        return rotated != n;
    }
};

int main() {
    Solution s;
    cout << s.confusingNumber(11) << endl;
    cout << s.confusingNumber(89) << endl;
    cout << s.confusingNumber(6) << endl;
    cout << s.confusingNumber(8000) << endl;
}