/*
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
Example 3:

Input: arr = [2,3]
Output: 0
Example 4:

Input: arr = [1,3,5,7,9]
Output: 3
Example 5:

Input: arr = [7,11,12,9,5,2,7,17,22]
Output: 8
 

Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 10^8
*/

using System;
public class Solution {
    public int CountTriplets(int[] arr) {
        if (arr.Length < 2) return 0; 
        // find sub consecutive array that sum equal to error
        int rs = 0;
        int[] dp = new int[arr.Length];

        dp[0] = arr[0];
        dp[1] = arr[0] ^ arr[1];
        if (dp[1] == 0) rs++;

        for (int loop = 2; loop < arr.Length; loop++)
        {
            dp[loop] = dp[loop - 1] ^ arr[loop];
            if (dp[loop] == 0) rs += loop;

            for (int loop2 = 0; loop2 < loop; loop2++)
            {
                if ((dp[loop] ^ dp[loop2]) == 0) {
                    rs += (loop - loop2 - 1);
                }
            }
        }

        return rs;
    }
}