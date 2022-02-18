/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
    int recursive(int n, vector<int>& dp) {
        if (dp[n] != -1) {
            return dp[n];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += recursive(i, dp) * recursive(n - i - 1, dp);
        }   
        
        dp[n] = ans;
        return dp[n];
    }
public:
    int numTrees(int n) {
        vector<int> dp = vector<int>(n + 1, -1);    
        dp[0] = 1;
        dp[1] = 1;
        // dp[2] = 2;

        return recursive(n, dp);
    }
};

int main() {
    Solution s;
    s.numTrees(3);
}