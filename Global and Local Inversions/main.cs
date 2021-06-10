/*
We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.
*/

using System;

public class Solution {
    private int L(int[] A) {
        int rs = 0;
        for (int loop = 1; loop < A.Length; loop++)
        {
            if (A[loop - 1] > A[loop]) rs++;
        }
        Console.WriteLine($"L: {rs}");
        return rs;
    }

    private int G(int[] A) {
        int rs = 0;
        for (int loop = A.Length - 1; loop >= 0 ; loop--)
        {
            int m = A.Length - A[loop] - 1;
            for (int loop2 = loop + 1; loop2 < A.Length; loop2++)
            {
                if (A[loop2] > A[loop]) m--;
            }

            rs += m;    
        }

        Console.WriteLine($"G: {rs}");
        return rs;
    }
    // 0 1 2 3 6 9 8 4 5 7
    public bool IsIdealPermutation(int[] A) {
        for (int loop = 0; loop < A.Length; loop++)
        {
            if (Math.Abs(loop - A[loop]) > 1) return false;
        }
        return true;
    }
}