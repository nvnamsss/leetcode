/*
Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

 

Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 3
Explanation: B = [4,6,3]
 

Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/

using System;
using System.Collections.Generic;

public class Solution {
    float findMedian(int[] A) {
        Array.Sort(A);
        if (A.Length % 2 == 0) return A[A.Length / 2];
        return A[A.Length / 2] + A[(A.Length - 1) / 2];
    }

    /*
        Min K   2K  3K  Max
        after changed => Min    K   Max
        Min K some1  2K some2 Max
        after chaned => Min Max

        Min Max K
        
        Min K   Max 2K
        4 6 10 - K = 5
        1 4 6 4- K = 3
    */
    public int SmallestRangeII(int[] A, int K) {
        int min = int.MaxValue;
        int max = int.MinValue;

        for (int loop = 0; loop < A.Length; loop++)
        {
            if (A[loop] > max) max = A[loop];
            if (A[loop] < min) min = A[loop];
        }

        int dif = max - min;
        if (dif <= K) return dif;

        float pivot = min + K;
        for (int loop = 0; loop < A.Length; loop++)
        {
            if (A[loop] < pivot) {
                A[loop] += Math.Abs(K);
            } else {
                if ((A[loop] == pivot && max + min > 2 * A[loop]) || (A[loop] > pivot && A[loop] < max - 2 * K)) {
                    A[loop] += Math.Abs(K);
                }else {
                    A[loop] -= Math.Abs(K);
                }
            }
        }

        min = int.MaxValue;
        max = int.MinValue;

        for (int loop = 0; loop < A.Length; loop++)
        {
            if (A[loop] > max) max = A[loop];
            if (A[loop] < min) min = A[loop];
        }

        return Math.Min(max - min, dif);
    }
}

/*
    p1: H: n head
        T: 90 - n tail
    p2: H: 10 - n head
        T: n tail

    example: H: 8 head
             T: 82 tail
             H: 2 head
             T: 8 tail
    flip the coin in p2 we got 2 tail and 8 head
*/