/*
Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.

Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.

 

Example 1:


Input: n = 4, k = 2
Output: 5
Explanation: 
The two line segments are shown in red and blue.
The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
Example 2:

Input: n = 3, k = 1
Output: 3
Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.
Example 3:

Input: n = 30, k = 7
Output: 796297179
Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.
Example 4:

Input: n = 5, k = 3
Output: 7
Example 5:

Input: n = 3, k = 2
Output: 1
 

Constraints:

2 <= n <= 1000
1 <= k <= n-1
*/

/*
Intuition
Case 1: Given n points, take k segments, allowed to share endpoints.
Same as:
Case 2: Given n + k - 1 points, take k segments, not allowed to share endpoints.


Prove
In case 2, for each solution,
remove one point after the segments,
then we got one valid solution for case 1.

Reversly also right.


Explanation
Easy combination number C(n + k - 1, 2k).


Complexity
Time O(NM), Space O(1), Invoving large integer operation.
Time O(N), Space O(N) using inverse number.
*/

using System;
using System.Collections.Generic;
using System.Numerics;
public class Solution {
    private BigInteger combination(int n, int k)
    {
        BigInteger rs = 1;
        int end = k * 2 + 1;    
        for (int loop = 1; loop < end ; loop++)
        {
            rs = rs * (n + k - loop);
            rs = rs / loop;
        }
        return rs;
    }

    //TLE, need an optimization
    public long Formula(int n, int k)
    {
        long count = 0;
        if (k == 1)
        {
            count = (n + 1) * (n + 1) - n * (n + 1) / 2 - 2 * n - 1;
            return count;
        }

        for (int loop = 2; loop <= n + 1 - k; loop++)
        {
            int p = n;
            while (p >= loop)
            {
                count += Formula(p + 1 - loop, k - 1);
                p--;
            }
        }
        return count;
    }
    public int NumberOfSets(int n, int k) {
        BigInteger amount = combination(n, k);
        long modulo = (long)Math.Pow(10, 9) + 7;
        int rs = (int)(amount % modulo); 
    
        return rs;
    }
}