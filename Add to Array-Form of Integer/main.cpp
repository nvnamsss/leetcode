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

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int digit = floor(log10(k)) + 1;
        vector<int> arr = vector<int>(digit, 0);
        int t = pow(10, digit - 1);
        for (int i = 0; i < digit; i++)
        {
            int v = k / t;
            k -= v * t;
            t /= 10;

            arr[i] = v;
        }
        
        if (arr.size() > num.size()) {
            swap(arr, num);
        }

        int r = 0;
        int j = num.size() - 1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int v = num[j] + arr[i] + r;
            num[j] = v % 10;
            r = v / 10;
            j--;
        }
        
        while (r > 0 && j >= 0) {
            int v = num[j] + r;
            num[j] = v % 10;
            r = v  / 10;
            j--;
        }

        if (r > 0) {
            num.insert(num.begin(), r);
        }
        return num;
    }
};

int main() {
    Solution s;
    vector<int> num = {9,9,9,9,9};
    s.addToArrayForm(num, 1);
}