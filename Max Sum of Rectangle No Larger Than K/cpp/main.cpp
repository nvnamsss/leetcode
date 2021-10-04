/*
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

 

Example 1:


Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
Example 2:

Input: matrix = [[2,2,-1]], k = 3
Output: 3
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-105 <= k <= 105
 

Follow up: What if the number of rows is much larger than the number of columns?
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int result = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = 0;

        vector<vector<int>> dp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i] += matrix[i][j];
            }
        }
        // m * (m + 1) / 2
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            for (int j = 0; j <= i; j++)
            {
                sum = sum + dp[j]
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result = max(result, sum);
            }
            /* code */
        }
        
        return result;
    }
};