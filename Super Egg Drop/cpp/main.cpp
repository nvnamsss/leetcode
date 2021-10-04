/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4
 

Constraints:

1 <= k <= 100
1 <= n <= 104
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        /*we easily see that this kind of Egg Drop problem is a variant of binary search
        in fact, binary search is SuperEggDrop with unlimited k.
        Following the above fact, we know that the minimum steps must be done is log(n)
        thus, firstly we find the nearest exponential value called t 
        that 2^t is the minimum value that greater than n.
        if t is less than k, then the minium steps x equal to t
        otherwise, we decrease n by dividing n by 2^k - 2, then apply 2 Egg to solve the rest

        intuitively, it just simply apply the binary search when we are rich, 
        when lack of eggs, we deliberate our move by switching to a slow but safe strategy 

        subproblem 1: find the minimum number t satisfy 2^t > n
        can we solve it by one step?
        we easily see that t = ceil(log2(n))

        but sometimes, binary search may not optimal thus we try to improve the 2 eggs problem
        says that with each egg, we can expand our step to a t value

        with two egg, we can optimally find the range x by sum(x -> 1) > n, similar with 3 eggs
        we can reduce the range n to fit with two egg. Thus we recursively solve this problem
        denote x be the minimum steps needed, with each egg we have the formula
        t + sigma(x -> k - 1) > nk        
        
        says that we have xk be the minimum steps needed in each range
        then x = sigma(x, 1 -> k)
        
        we have x = x1 + x2 + x3 + ... + xk
        due to x * (x + 1) > 2 * n
        due to k values of x, each xk has the same characteristic thus x * x * (x + 1) > 2 * n
        (x3 + x2 + x1) + (x3 + 1 + x2 - 1 + x1 -2)  
        xk = x[k - 1] + x[k - 1] 
        (xk + x[k - 1]) + (xk + 1 + x[k - 1] - 1) + ... + (xk + k + x[k - 1] - k)

        generic for k = 2, k = 1
        k = 1 -> n / x1 = n
        k = 2 -> n / x2 / x1 = n / x2 ->    
        k = 3 -> n / x3 / x2 / x1 = n / x3 / x2

        we denote rev(k, n) for indicating the amount of steps needed with k and n
        we have rev(1, n) = n, rev(2, n) = range(1 -> ?, rev(1, n / t - i))
        similar rev(3, n) = range(1 -> ?, rev(2, n / t - i))
        due to the problem is recurrence thus we can apply dp to eliminate the redundant steps
        rev(k, n) return n / x + rev(k - 1, n / x - 1)
        from 1 -> n find min(rev)
        
        pi(x, k) >= n, sigma(x, k), max(range(x, k)) be the min
        n = 9999, k = 2 => x = 100, then if we increase k, how do we optimize our move?
        with an extra k 

        i.e: with 9999 we have x equal to 100
        */

        if (k == 1)
            return n;
        int x = 1;
        // int t = ceil(log2(n));
        // if (k >= t) return t;
        // n = n / pow(2, k - 2);
        int nn = n * 3;

        while (x * (x + 1) * (x + 2) < nn)
        {
            x++;
        }
        return x;
    }

    int recursive(int k, int n)
    {
        if (k == 1)
            return n;
        if (k == 2)
        {
            int x = 1;
            int nn = n * 2;

            while (x * (x + 1) < nn)
            {
                x++;
            }
            return x;
        }

        int x = 1;
        int y = recursive(k - 1, n / x);
        while (x > y) {
            x = x + 1;
            y = recursive(k - 1, n / x);
        }

        return x;
    }
};