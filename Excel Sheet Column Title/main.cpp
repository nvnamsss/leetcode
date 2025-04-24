/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
 

Constraints:

1 <= columnNumber <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

// a * r^k + b * r^k-1 + c * r^k-2 + ... + x * r^0
// 1 * 27 * 27 + 1 * 27 + 1
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            columnNumber--;
            int v = columnNumber % 26;
            columnNumber = (columnNumber - v) / 26;
            char c = v + 'A';
            ans = c + ans;
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(701) << endl;
    cout << s.convertToTitle(703) << endl;
}