// Implement int sqrt(int x).

// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

// Example 1:

// Input: 4
// Output: 2
// Example 2:

// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.

public class Solution {
    public int MySqrt(int x) {
       if (x < 2) return x;
            int start = 1;
            int end = x / 2;
            int res = 0;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (mid == x / mid) return mid;
                
                if (mid < x/mid)
                {
                    res = mid;
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
       
       return res;
    }
}