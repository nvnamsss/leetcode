using System;
using System.Collections;
using System.Collections.Generic;


// Given an integer array arr, count element x such that x + 1 is also in arr.

// If there're duplicates in arr, count them seperately.

 

// Example 1:

// Input: arr = [1,2,3]
// Output: 2
// Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
// Example 2:

// Input: arr = [1,1,3,3,5,5,7,7]
// Output: 0
// Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
// Example 3:

// Input: arr = [1,3,2,3,5,0]
// Output: 3
// Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
// Example 4:

// Input: arr = [1,1,2,2]
// Output: 2
// Explanation: Two 1s are counted cause 2 is in arr.
 

// Constraints:

// 1 <= arr.length <= 1000
// 0 <= arr[i] <= 1000
public class Solution {
    public int CountElements(int[] arr) {
        Dictionary<int, int> set = new Dictionary<int, int>();
        for (int loop = 0; loop < arr.Length; loop++)
        {
            if (!set.ContainsKey(arr[loop]))
            {
                set.Add(arr[loop],0);
            }

            set[arr[loop]] += 1;
        }
        int count = 0;
        foreach (var entry in set)
        {
            if (set.ContainsKey(entry.Key + 1))
            {
                count += entry.Value;
            }
        }

        return count;
    }
}