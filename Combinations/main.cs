/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
*/

using System;
using System.Collections.Generic;

public class Solution {
    List<IList<int>> result;
    private void combination(int n, List<int> list, int start, int k)
    {
        if (list.Count == k)
        {
            result.Add(new List<int>(list));
            return;
        }

        for (int loop = start; loop <= n; loop++)
        {
            list.Add(loop);
            combination(n, list, loop + 1, k);
            list.RemoveAt(list.Count - 1);
        }
    }

    public IList<IList<int>> Combine(int n, int k) {
        result = new List<IList<int>>();
        combination(n, new List<int>(), 1, k);

        return result;
    }
}