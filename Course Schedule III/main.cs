/*
There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.

 

Example 1:

Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
Example 2:

Input: courses = [[1,2]]
Output: 1
Example 3:

Input: courses = [[3,2],[4,3]]
Output: 0
 

Constraints:

1 <= courses.length <= 104
1 <= durationi, lastDayi <= 104s
*/

using System;
using System.Collections.Generic;
public class Solution {
    public int ScheduleCourse(int[][] courses) {
        int rs = 0;
        int day = 0;
        Array.Sort(courses, (a, b) => {
            return a[1].CompareTo(b[1]);
        });
        SortedSet<int> s = new SortedSet<int>();
        for (int loop = 0; loop < courses.Length; loop++)
        {
            int[] c = courses[loop];
            if (day + c[0] <= c[1]) {
                day = day + c[0];
                s.Add(c[0]);
            } else {
                // replace
                if (s.Max > c[0]) {
                    day = day - s.Max + c[0];
                    s.Remove(s.Max);
                    s.Add(c[0]);
                }
            }
        }

        return s.Count;       
    }

}

// void main() {
//     Solution s = Solution();
//     int[][] courses = new int[][]{

//     };
//     s.ScheduleCourse()
// }