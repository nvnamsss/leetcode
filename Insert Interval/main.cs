/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
using System;
using System.Collections.Generic;
public class Solution {
    private int[] overlap(int[] a, int[] b)
    {
        if (a[0] <= b[0] && a[1] > b[0])
        {
            return new int[] {a[0], Math.Max(b[1], a[1])};
        }

        if (b[0] <= a[0] && b[1] >= a[0])
        {
            return new int[] {b[0], Math.Max(a[1], b[1])};
        }

        return null;
    }

    public int[][] Insert(int[][] intervals, int[] newInterval) {
        List<int[]> rs=  new List<int[]>();
        int[] interval = newInterval;
        for (int loop = 0; loop < intervals.Length; loop++)
        {
            bool merged = false;
            int[] r;
            while (loop < intervals.Length && (r = overlap(intervals[loop], interval)) != null)
            {
                interval = r;
                loop++;
                merged = true;
            }
            rs.Add(merged ? interval : intervals[loop]);
        }       

        return rs.ToArray();
    }
}