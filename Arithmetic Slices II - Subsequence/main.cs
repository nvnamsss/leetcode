/*
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7
 
A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.

The function should return the number of arithmetic subsequence slices in the array A.

The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.

 
Example:

Input: [2, 4, 6, 8, 10]

Output: 7

Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
*/

using System;
using System.Collections.Generic;
public class Solution
{
    public static long nCr(int n, int r)
    {
        // naive: return Factorial(n) / (Factorial(r) * Factorial(n - r));
        return nPr(n, r) / Factorial(r);
    }

    public static long nPr(int n, int r)
    {
        // naive: return Factorial(n) / Factorial(n - r);
        return FactorialDivision(n, n - r);
    }

    private static long FactorialDivision(int topFactorial, int divisorFactorial)
    {
        long result = 1;
        for (int i = topFactorial; i > divisorFactorial; i--)
            result *= i;
        return result;
    }

    private static long Factorial(int i)
    {
        if (i <= 1)
            return 1;
        return i * Factorial(i - 1);
    }
    public int subsequence(int k, int change)
    {
        if (k == 3) return 1;
        int ret = 1;
        if (change == 0)
        {
            for (int loop = 3; loop < k; loop++)
            {
                ret += (int)nCr(k, loop);
            }

            return ret;
        }

        int m = 1;
        int v;
        while (Math.Round((float)k / m) >= 3)
        {
            int n = (k + m) / (m + 1);
            v = m * (n - 1) + n;
            if (v == k)
            {
                ret++;
            }
            m++;
        }

        return ret;
    }

    public int recursive(int k, int c)
    {
        if (k < 3) return 0;
        int ret = subsequence(k, c);
        if (c == 0) return ret;

        for (int loop = k - 1; loop >= 3; loop--)
        {
            ret += (k - loop + 1) * subsequence(loop, c);
        }
        return ret;
    }

    public int ConsecutiveArithmeticSlices(int[] A)
    {
        int k = 0;
        int c = 0;
        int ret = 0;

        for (int loop = 2; loop < A.Length; loop++)
        {
            if (A[loop] - A[loop - 1] != c)
            {
                if (k > 2)
                {
                    ret += recursive(k, c);
                }

                k = 1;
                c = A[loop] - A[loop - 1];
            }
            else
            {
                k++;
            }
        }
        ret += recursive(k, c);
        return ret;
    }

    public int NumberOfArithmeticSlices(int[] A)
    {

        Dictionary<int, int>[] map = new Dictionary<int, int>[A.Length];
        int ret = 0;
        for (int loop = 0; loop < A.Length; loop++)
        {
            map[loop] = new Dictionary<int, int>();
            for (int loop2 = 0; loop2 < loop; loop2++)
            {
                long delta = (long)A[loop] - (long)A[loop2];
                if (delta < int.MinValue || delta > int.MaxValue) continue;

                int dif = (int)delta;
                if (!map[loop2].ContainsKey(dif)) map[loop2].Add(dif, 0);
                if (!map[loop].ContainsKey(dif)) map[loop].Add(dif, 0);

                int sum = map[loop2][dif];
                int origin = map[loop][dif];
                map[loop][dif] = origin + sum + 1;
                ret += sum;
            }
        }

        return ret;
    }
}