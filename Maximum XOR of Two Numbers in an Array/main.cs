/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/
using System;
using System.Collections.Generic;
public class TrieNode{
    public TrieNode left;
    public TrieNode right;
}

public class Solution {
    TrieNode Insert(int n, TrieNode head)
    {
        TrieNode cur = head;
        for (int loop = 31; loop >= 0; loop--)
        {
            int bit = (n >> loop) & 1;
            if (bit == 0)
            {
                if (cur.left == null) cur.left = new TrieNode();
                cur = cur.left;
            }
            else {
                if (cur.right == null) cur.right = new TrieNode();
                cur = cur.right;
            }
        }

        return head;
    }

    private int maxor(TrieNode head, int[] nums)
    {
        int max = int.MinValue;

        for (int loop = 0; loop < nums.Length; loop++)
        {
            TrieNode cur = head;
            int current_value = 0;
            for (int loop2 = 31; loop2 >= 0; loop2--)
            {
                int bit = (nums[loop] >> loop2) & 1;
                if (bit == 0)
                {
                    if (cur.right != null)
                    {
                        current_value += Math.Pow(2, loop2);
                        cur = cur.right;
                    }
                    else cur = cur.left;
                }
                else {
                    if (cur.left != null)
                    {
                        current_value += Math.Pow(2, loop2);
                        cur = cur.left;
                    }
                    else cur = cur.right;
                }
            }

            max = Math.Max(max, current_value);
        }

        return max;
    }

    public int FindMaximumXOR(int[] nums) {
        TrieNode head = new TrieNode();
        for (int loop = 0; loop < nums.Length; loop++)
        {
            head = Insert(nums[loop], head);
        }

        return maxor(head, nums);
    }
}