/*
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.
*/
using System;
using System.Collections.Generic;
public class Solution {
    public bool ValidateStackSequences(int[] pushed, int[] popped) {
        Dictionary<int, int> pushIndexer = new Dictionary<int, int>();
        HashSet<int> popIndexer = new HashSet<int>();
        for (int loop = 0; loop < pushed.Length; loop++)
        {
            pushIndexer.Add(pushed[loop], loop);
        }

        int ceil = -1;
        for (int loop = 0; loop < popped.Length; loop++)
        {
            int pop = popped[loop];
            int i = pushIndexer[pop];
            popIndexer.Add(i);
            if (ceil != -1 && i < ceil) {
                Console.WriteLine($"False at: {pop} - I: {i} - Ceil: {ceil}");
                return false;
            }

            while (popIndexer.Contains(i - 1)) {
                i--;
            }
            ceil = i - 1;
        }
        return true;
    }
}