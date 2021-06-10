/*
Kate was given a birthday gift of three theater tickets. Now she is browsing the theater program for the next N days. On the program, performances are named by integers. Every day, one performance is staged. Kate wants to choose three days (not necessarily consecutive) to go to the theater.

In how many ways can she use her tickets? Two ways are different if the sequences of watched performances are different. Kate likes the theater, so she may watch one performance more than once. For example, if N = 4 and theater program looks as following: [1, 2, 1, 1], Kate has four possibilities to choose the dates: [1, 2, 1, 1], [1, 2, 1, 1], [1, 2, 1, 1], and [1, 2, 1, 1], but they create only three different sequences: (1, 2, 1), (1, 1, 1) and (2, 1, 1). The correct answer for this example is 3. Notice that the order of performances matters, so the first and the last sequences are considered different.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, denoting names of performances for the next N days, returns the number of possible ways to spend the tickets. Since the answer can be very large, provide it modulo 109 + 7 (1,000,000,007).

For example, given A = [1, 2, 1, 1], the function should return 3 as exmplained above.

Given A = [1, 2, 3, 4], the function should return 4. There are four ways to spend tickets: (1, 2, 3), (1, 2, 4), (1, 3, 4) and (2, 3, 4).

Given A = [2, 2, 2, 2], the function should return 1. There is only one way to spend tickets: (2, 2, 2).

Given A = [2, 2, 1, 2, 2], the function should return 4. There are four ways to spend tickets: (1, 2, 2), (2, 1, 2), (2, 2, 1) and (2, 2, 2).

Given A = [1, 2], the function should return 0. Kate cannot use all three tickets in only two days.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [1..N].
*/
using System;
using System.Collections.Generic;
class Solution {
    public static int MOD = 1000000007;

    public int solution(int[] A) {
        int rs = 0;
        int[][] dp = new int[2][];
        HashSet<int> set = new HashSet<int>();
        Dictionary<int, int> map = new Dictionary<int, int>();

        for (int loop = 0; loop < 2; loop++)
        {
            dp[loop] = new int[A.Length];    
        }
        
        for (int loop = 0; loop < A.Length; loop++)
        {
            if (!set.Contains(A[loop])) set.Add(A[loop]);

            dp[0][loop] = set.Count;
        }

        set.Clear();
        for (int loop = A.Length - 1; loop >= 0 ; loop--)
        {
            if (!set.Contains(A[loop])) set.Add(A[loop]);

            dp[1][loop] = set.Count;   
        }

        for (int loop = 1; loop < A.Length - 1; loop++)
        {
            long dleft = dp[0][loop - 1];
            long dright = dp[1][loop + 1];
            
            bool contains = map.ContainsKey(A[loop]);
            if (!contains) {
                map.Add(A[loop], 0);
            } else {
                dleft = dleft - map[A[loop]];
            }

            rs += (int)((dleft * dright) % MOD);
            rs = rs % MOD;
            map[A[loop]] = dp[0][loop - 1];
        }
        return rs;
    }

}
