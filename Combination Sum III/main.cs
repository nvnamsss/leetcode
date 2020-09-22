/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
using System;
using System.Collections.Generic;
public class Solution {
    List<IList<int>> rs;
    private List<int[]> combinationSum2(int k)
    {
        List<int[]> com = new List<int[]>();
        for (int loop = 1; loop < k / 2; loop++)
        {
            com.Add(new int[]{loop, k - loop});
        }

        return com;
    }   

    private List<int[]> combinationSumk(List<int> l, int k, int target)
    {
        if (target == 0)
        {
            rs.Add(l);
        }

        for (int loop = target - k; loop > k; loop++)
        {
            l.Add(loop);
            combinationSumk(l, k - 1, target - loop);
        }
    }

    public IList<IList<int>> CombinationSum3(int k, int n) {
        rs = new List<IList<int>>();
        for (int loop = n - k; loop > k; loop--)
        {
            List<int> l = new List<int>(){loop};
            combinationSumk(l, k, n - loop);
        }

        return rs;
    }
}