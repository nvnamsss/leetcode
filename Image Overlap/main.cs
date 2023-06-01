/*
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1
*/

using System;
using System.Collections.Generic;
public class Solution {

    private List<KeyValuePair<int, int>> NonZero(int[][] A)
    {
        List<KeyValuePair<int, int>> rs = new List<KeyValuePair<int, int>>();
        for (int loop = 0; loop < A.Length; loop++)
        {
            for (int loop2 = 0; loop2 < A.Length; loop2++)
            {
                if (A[loop][loop2] != 0)
                {
                    rs.Add(new KeyValuePair<int, int>(loop, loop2));
                }
            }
        }

        return rs;
    }

    public int LargestOverlap(int[][] A, int[][] B) {
            List<KeyValuePair<int, int>> a = NonZero(A);
            List<KeyValuePair<int, int>> b = NonZero(B);
            Dictionary<KeyValuePair<int, int>, int> d = new Dictionary<KeyValuePair<int, int>, int>();

            int max = 0;
            for (int loop = 0; loop < a.Count; loop++)
            {
                for (int loop2 = 0; loop2 < b.Count; loop2++)
                {
                    int dr = a[loop].Key - b[loop].Key;
                    int dc = a[loop].Value - b[loop].Value;
                    KeyValuePair<int, int> dif = new KeyValuePair<int, int>(dr, dc);

                    if (!d.ContainsKey(dif))
                    {
                        d.Add(dif, 0);
                    }

                    d[dif] += 1;
                    max = Math.Max(max, d[dif]);
                }
            }

            return max;
    }

    public int simple(int[][] A, int[][] B)
    {
                int res = 0;
        int N = A.Length;
        var count = new int[N * 2, N * 2];
        for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] == 0) continue;
            for (int m = 0; m < N; m++) {
                for (int n = 0; n < N; n++)
                            {
                                if (B[m][n] == 0) continue;
                                res = Math.Max(res, ++count[N + i - m, N + j - n]);
                            }
            }
            
        }

        return res;
    }
}