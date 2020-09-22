/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/

using System;
using System.Collections.Generic;

public class Solution {
    public int generate(int digit, int start)
    {
        int rs = 0;
        for (int loop = start; loop <= 10 - digit; loop++)
        {
            rs *= 10;
            rs += loop;
        }

        return rs;
    }

    public IList<int> SequentialDigits(int low, int high) {
        List<int> result = new List<int>();
        int dl = Math.Floor(Math.Log10(low) +1);
        int dh = Math.Floor(Math.Log10(high) + 1);

        for (int loop = dl; loop <= dh; loop++)
        {
            int start = 1;

            while (start <= 10 - loop)
            {
                int number = generate(loop, start);
                if (number >= low && number <= high)
                    result.Add(number);
                start += 1;
            }
        }

        return result;
    }
}