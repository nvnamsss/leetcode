/*
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
 

Constraints:

1 <= num.length <= 104
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 104


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int digits = floor(log10(k) + 1);
        int n = num.size();
        vector<int> ans = vector<int>(max(n, digits));
        int r = 0;
        int m = ans.size() - min(n, digits);
        int dif = ans.size() - n;
        for (int i = 0; i < n; i++)
        {
            ans[i + dif] = num[i];
        }

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            int v = k % 10;
            k = k / 10;
            ans[i] += v + r;
            r = ans[i] / 10;
            ans[i] = ans[i] % 10;
        }

        if (r > 0)
        {
            ans.insert(ans.begin(), r);
        }

        return ans;
    }
};