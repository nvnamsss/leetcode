/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        List<IList<int>> rs = new List<IList<int>>();
        for (int loop = 0; loop < numRows; loop++)
        {
            List<int> added = new List<int>();
            if (loop == 0)
            {
                added.Add(1);
            }
            else {
                IList<int> last = rs[loop - 1];
                int l = loop + 1;
                for (int loop2 = 0; loop2 < l; loop2++)
                {
                    int upperleft = loop2 - 1 >= 0 ? last[loop2 - 1] : 0;
                    int upperright = loop2 < last.Count ? last[loop2] : 0;
                    added.Add(upperleft + upperright); 
                }
            }

            rs.Add(added);
        }

        return rs;
    }
}