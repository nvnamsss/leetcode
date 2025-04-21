/*Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.



Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.


Constraints:

1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int binarySearch(vector<int> &arr, int target)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m] <= target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return l;
    }

public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        vector<unordered_map<int, int>> dp = vector<unordered_map<int, int>>(arr1.size() + 1);
        sort(arr2.begin(), arr2.end());
        dp[0].insert({-1, 0});

        for (int i = 0; i < arr1.size(); i++)
        {
            for (auto&&it : dp[i]) {
                if (arr1[i] > it.first) {
                    if (dp[i+1].find(arr1[i]) == dp[i+1].end()) {
                        dp[i+1].insert(arr1[i], INT32_MAX);
                    }

                    dp[i+1][arr1[i]] = min(dp[i+1][arr1[i]], it.second);
                }

                int l = binarySearch(arr2, it.first);
                if (l < arr2.size()) {
                    if (dp[i+1].find(arr2[l]) == dp[i+1].end()) {
                        dp[i+1].insert(arr2[l], INT32_MAX);
                    }

                    dp[i+1][arr2[l]] = min(dp[i+1][arr2[l]], it.second + 1);
                }
            }
        }

        int ans = INT32_MAX;
        for (auto &&it : dp[arr1.size() - 1])
        {
            ans = min(ans, it.second);
        }

        return ans == INT32_MAX ? -1 : ans;
    }
};