/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

using System;
public class Solution {
    public int ClimbStairs(int n) {
        int dp1 = 1;
        int dp2 = 2;

        for (int loop = 2; loop < n; loop++)
        {
            if (loop % 2 == 0)
            {
                dp1 = dp1 + dp2;   
            }
            else {
                dp2 = dp1 + dp2;
            }
        }

        return n % 2 == 0? dp 2: dp1; 
    }
}