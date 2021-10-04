/*
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
 

Example 1:

Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
Example 2:

Input: arr = [4,8,12,16]
Output: 2
Example 3:

Input: arr = [100]
Output: 1
 

Constraints:

1 <= arr.length <= 4 * 104
0 <= arr[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i + 1]) continue;
            bool sign = arr[i] < arr[i + 1];
            int j = i + 1;

            for (; j < arr.size() - 1; j++)
            {
                if ((arr[j] == arr[j + 1]) || (sign == arr[j] < arr[j + 1])) {
                    break;
                } 
                sign = !sign;
            }
            ans = max(ans, j - i + 1);
            i = j - 1;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = vector<int>{9,4,2,10,7,8,8,1,9};
    int rs = s.maxTurbulenceSize(arr);
    cout << "result: " << rs << " expect: 5" << endl;

    arr = vector<int>{2,0,2,4,2,5,0,1,2,3};
    rs = s.maxTurbulenceSize(arr);
    cout << "result: " << rs << " expect: 6" << endl;
}