/*
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

Example 1:


Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
Example 2:


Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
 

Constraints:

1 <= n <= 231 - 1
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long n2 = (long)n * 2;
        long v = floor(sqrt(n2));
        while (v * (v+1) <= n2) {
            v = v + 1;
        }

        return v - 1;
    }
};

int main() {
    Solution s;
    int rs = s.arrangeCoins(5);
    cout << rs << endl;
    rs = s.arrangeCoins(8);
    cout << rs << endl;
    rs = s.arrangeCoins(14);
    cout << rs << endl;
    rs = s.arrangeCoins(15);
    cout << rs << endl;
    rs = s.arrangeCoins(16);
    cout << rs << endl;
    rs = s.arrangeCoins(1232);
    cout << rs << endl;
}